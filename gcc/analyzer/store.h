/* Classes for modeling the state of memory.
   Copyright (C) 2020 Free Software Foundation, Inc.
   Contributed by David Malcolm <dmalcolm@redhat.com>.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_ANALYZER_STORE_H
#define GCC_ANALYZER_STORE_H

/* Implementation of the region-based ternary model described in:
     "A Memory Model for Static Analysis of C Programs"
      (Zhongxing Xu, Ted Kremenek, and Jian Zhang)
     http://lcs.ios.ac.cn/~xuzb/canalyze/memmodel.pdf  */

/* The store models memory as a collection of "clusters", where regions
   are partitioned into clusters via their base region.

   For example, given:
     int a, b, c;
     struct coord { double x; double y; } verts[3];
   then "verts[0].y" and "verts[1].x" both have "verts" as their base region.
   Each of a, b, c, and verts will have their own clusters, so that we
   know that writes to e.g. "verts[1].x".don't affect e.g. "a".

   Within each cluster we store a map of bindings to values, where the
   binding keys can be either concrete or symbolic.

   Concrete bindings affect a specific range of bits relative to the start
   of the base region of the cluster, whereas symbolic bindings affect
   a specific subregion within the cluster.

   Consider (from the symbolic-1.c testcase):

     char arr[1024];
     arr[2] = a;  (1)
     arr[3] = b;  (2)
       After (1) and (2), the cluster for "arr" has concrete bindings
       for bits 16-23 and for bits 24-31, with svalues "INIT_VAL(a)"
       and "INIT_VAL(b)" respectively:
       cluster: {bits 16-23: "INIT_VAL(a)",
                 bits 24-31: "INIT_VAL(b)";
                 flags: {}}
       Attempting to query unbound subregions e.g. arr[4] will
       return "UNINITIALIZED".
       "a" and "b" are each in their own clusters, with no explicit
       bindings, and thus implicitly have value INIT_VAL(a) and INIT_VAL(b).

     arr[3] = c;  (3)
       After (3), the concrete binding for bits 24-31 is replaced with the
       svalue "INIT_VAL(c)":
       cluster: {bits 16-23: "INIT_VAL(a)",  (from before)
                 bits 24-31: "INIT_VAL(c)";  (updated)
                 flags: {}}

     arr[i] = d;  (4)
       After (4), we lose the concrete bindings and replace them with a
       symbolic binding for "arr[i]", with svalue "INIT_VAL(d)".  We also
       mark the cluster as having been "symbolically touched": future
       attempts to query the values of subregions other than "arr[i]",
       such as "arr[3]" are "UNKNOWN", since we don't know if the write
       to arr[i] affected them.
       cluster: {symbolic_key(arr[i]): "INIT_VAL(d)";
                 flags: {TOUCHED}}

     arr[j] = e;  (5)
       After (5), we lose the symbolic binding for "arr[i]" since we could
       have overwritten it, and add a symbolic binding for "arr[j]".
       cluster: {symbolic_key(arr[j]): "INIT_VAL(d)"; (different symbolic
                 flags: {TOUCHED}}                     binding)

     arr[3] = f;  (6)
       After (6), we lose the symbolic binding for "arr[j]" since we could
       have overwritten it, and gain a concrete binding for bits 24-31
       again, this time with svalue "INIT_VAL(e)":
       cluster: {bits 24-31: "INIT_VAL(d)";
                 flags: {TOUCHED}}
       The cluster is still flagged as touched, so that we know that
       accesses to other elements are "UNKNOWN" rather than
       "UNINITIALIZED".

   Handling symbolic regions requires us to handle aliasing.

   In the first example above, each of a, b, c and verts are non-symbolic
   base regions and so their clusters are "concrete clusters", whereas given:
       struct coord *p, *q;
   then "*p" and "*q" are symbolic base regions, and thus "*p" and "*q"
   have "symbolic clusters".

   In the above, "verts[i].x" will have a symbolic *binding* within a
   concrete cluster for "verts", whereas "*p" is a symbolic *cluster*.

   Writes to concrete clusters can't affect other concrete clusters,
   but can affect symbolic clusters; e.g. after:
       verts[0].x = 42;
   we bind 42 in the cluster for "verts", but the clusters for "b" and "c"
   can't be affected.  Any symbolic clusters for *p and for *q can be
   affected, *p and *q could alias verts.

   Writes to a symbolic cluster can affect other clusters, both
   concrete and symbolic; e.g. after:
       p->x = 17;
   we bind 17 within the cluster for "*p".  The concrete clusters for a, b,
   c, and verts could be affected, depending on whether *p aliases them.
   Similarly, the symbolic cluster to *q could be affected.  */

namespace ana {

class concrete_binding;

/* An enum for discriminating between "direct" vs "default" levels of
   mapping.  */

enum binding_kind
{
  /* Special-case value for hash support.
     This is the initial entry, so that hash traits can have
     empty_zero_p = true.  */
  BK_empty = 0,

  /* Special-case value for hash support.  */
  BK_deleted,

  /* The normal kind of mapping.  */
  BK_direct,

  /* A lower-priority kind of mapping, for use when inheriting
     default values from a parent region.  */
  BK_default
};

extern const char *binding_kind_to_string (enum binding_kind kind);

/* Abstract base class for describing ranges of bits within a binding_map
   that can have svalues bound to them.  */

class binding_key
{
public:
  virtual ~binding_key () {}
  virtual bool concrete_p () const = 0;
  bool symbolic_p () const { return !concrete_p (); }

  static const binding_key *make (store_manager *mgr, const region *r,
				   enum binding_kind kind);

  virtual void dump_to_pp (pretty_printer *pp, bool simple) const;
  void dump (bool simple) const;

  static int cmp_ptrs (const void *, const void *);
  static int cmp (const binding_key *, const binding_key *);

  virtual const concrete_binding *dyn_cast_concrete_binding () const
  { return NULL; }

  enum binding_kind get_kind () const { return m_kind; }

  void mark_deleted () { m_kind = BK_deleted; }
  void mark_empty () { m_kind = BK_empty; }
  bool is_deleted () const { return m_kind == BK_deleted; }
  bool is_empty () const { return m_kind == BK_empty; }

protected:
  binding_key (enum binding_kind kind) : m_kind (kind) {}

  hashval_t impl_hash () const
  {
    return m_kind;
  }
  bool impl_eq (const binding_key &other) const
  {
    return m_kind == other.m_kind;
  }

private:
  enum binding_kind m_kind;
};

/* Concrete subclass of binding_key, for describing a concrete range of
   bits within the binding_map (e.g. "bits 8-15").  */

class concrete_binding : public binding_key
{
public:
  /* This class is its own key for the purposes of consolidation.  */
  typedef concrete_binding key_t;

  concrete_binding (bit_offset_t start_bit_offset, bit_size_t size_in_bits,
		    enum binding_kind kind)
  : binding_key (kind),
    m_start_bit_offset (start_bit_offset),
    m_size_in_bits (size_in_bits)
  {}
  bool concrete_p () const FINAL OVERRIDE { return true; }

  hashval_t hash () const
  {
    inchash::hash hstate;
    hstate.add_wide_int (m_start_bit_offset);
    hstate.add_wide_int (m_size_in_bits);
    return hstate.end () ^ binding_key::impl_hash ();
  }
  bool operator== (const concrete_binding &other) const
  {
    if (!binding_key::impl_eq (other))
      return false;
    return (m_start_bit_offset == other.m_start_bit_offset
	    && m_size_in_bits == other.m_size_in_bits);
  }

  void dump_to_pp (pretty_printer *pp, bool simple) const FINAL OVERRIDE;

  const concrete_binding *dyn_cast_concrete_binding () const FINAL OVERRIDE
  { return this; }

  bit_offset_t get_start_bit_offset () const { return m_start_bit_offset; }
  bit_size_t get_size_in_bits () const { return m_size_in_bits; }
  /* Return the next bit offset after the end of this binding.  */
  bit_offset_t get_next_bit_offset () const
  {
    return m_start_bit_offset + m_size_in_bits;
  }

  bool overlaps_p (const concrete_binding &other) const;

private:
  bit_offset_t m_start_bit_offset;
  bit_size_t m_size_in_bits;
};

} // namespace ana

template <> struct default_hash_traits<ana::concrete_binding>
: public member_function_hash_traits<ana::concrete_binding>
{
  static const bool empty_zero_p = true;
};

namespace ana {

/* Concrete subclass of binding_key, for describing a symbolic set of
   bits within the binding_map in terms of a region (e.g. "arr[i]").  */

class symbolic_binding : public binding_key
{
public:
  /* This class is its own key for the purposes of consolidation.  */
  typedef symbolic_binding key_t;

  symbolic_binding (const region *region, enum binding_kind kind)
  : binding_key (kind),
    m_region (region)
  {}
  bool concrete_p () const FINAL OVERRIDE { return false; }

  hashval_t hash () const
  {
    return (binding_key::impl_hash () ^ (long)m_region);
  }
  bool operator== (const symbolic_binding &other) const
  {
    if (!binding_key::impl_eq (other))
      return false;
    return (m_region == other.m_region);
  }

  void dump_to_pp (pretty_printer *pp, bool simple) const FINAL OVERRIDE;

  const region *get_region () const { return m_region; }

private:
  const region *m_region;
};

} // namespace ana

template <> struct default_hash_traits<ana::symbolic_binding>
: public member_function_hash_traits<ana::symbolic_binding>
{
  static const bool empty_zero_p = true;
};

namespace ana {

/* A mapping from binding_keys to svalues, for use by binding_cluster
   and compound_svalue.  */

class binding_map
{
public:
  typedef hash_map <const binding_key *, const svalue *> map_t;
  typedef map_t::iterator iterator_t;

  binding_map () : m_map () {}
  binding_map (const binding_map &other);
  binding_map& operator=(const binding_map &other);

  bool operator== (const binding_map &other) const;
  bool operator!= (const binding_map &other) const
  {
    return !(*this == other);
  }

  hashval_t hash () const;

  const svalue *get (const binding_key *key) const
  {
    const svalue **slot = const_cast<map_t &> (m_map).get (key);
    if (slot)
      return *slot;
    else
      return NULL;
  }
  bool put (const binding_key *k, const svalue *v)
  {
    gcc_assert (v);
    return m_map.put (k, v);
  }

  void remove (const binding_key *k) { m_map.remove (k); }
  void empty () { m_map.empty (); }

  iterator_t begin () const { return m_map.begin (); }
  iterator_t end () const { return m_map.end (); }
  size_t elements () const { return m_map.elements (); }

  void dump_to_pp (pretty_printer *pp, bool simple, bool multiline) const;
  void dump (bool simple) const;

  bool apply_ctor_to_region (const region *parent_reg, tree ctor,
			     region_model_manager *mgr);

private:
  bool apply_ctor_val_to_range (const region *parent_reg,
				region_model_manager *mgr,
				tree min_index, tree max_index,
				tree val);
  bool apply_ctor_pair_to_child_region (const region *parent_reg,
					region_model_manager *mgr,
					tree index, tree val);

  map_t m_map;
};

/* Concept: BindingVisitor, for use by binding_cluster::for_each_binding
   and store::for_each_binding.

   Should implement:
     void on_binding (const binding_key *key, const svalue *&sval);
*/

/* All of the bindings within a store for regions that share the same
   base region.  */

class binding_cluster
{
public:
  friend class store;

  typedef hash_map <const binding_key *, const svalue *> map_t;
  typedef map_t::iterator iterator_t;

  binding_cluster (const region *base_region)
  : m_base_region (base_region), m_map (),
    m_escaped (false), m_touched (false) {}
  binding_cluster (const binding_cluster &other);
  binding_cluster& operator=(const binding_cluster &other);

  bool operator== (const binding_cluster &other) const;
  bool operator!= (const binding_cluster &other) const
  {
    return !(*this == other);
  }

  hashval_t hash () const;

  bool symbolic_p () const;

  void dump_to_pp (pretty_printer *pp, bool simple, bool multiline) const;
  void dump (bool simple) const;

  void bind (store_manager *mgr, const region *, const svalue *,
	     binding_kind kind);

  void clobber_region (store_manager *mgr, const region *reg);
  void purge_region (store_manager *mgr, const region *reg);
  void zero_fill_region (store_manager *mgr, const region *reg);
  void mark_region_as_unknown (store_manager *mgr, const region *reg);

  const svalue *get_binding (store_manager *mgr, const region *reg,
			      binding_kind kind) const;
  const svalue *get_binding_recursive (store_manager *mgr,
					const region *reg,
					enum binding_kind kind) const;
  const svalue *get_any_binding (store_manager *mgr,
				  const region *reg) const;
  const svalue *maybe_get_compound_binding (store_manager *mgr,
					     const region *reg) const;

  void remove_overlapping_bindings (store_manager *mgr, const region *reg);

  template <typename T>
  void for_each_value (void (*cb) (const svalue *sval, T user_data),
		       T user_data)
  {
    for (map_t::iterator iter = m_map.begin (); iter != m_map.end (); ++iter)
      cb ((*iter).second, user_data);
  }

  static bool can_merge_p (const binding_cluster *cluster_a,
			   const binding_cluster *cluster_b,
			   binding_cluster *out_cluster,
			   store_manager *mgr,
			   model_merger *merger);
  void make_unknown_relative_to (const binding_cluster *other_cluster,
				 store_manager *mgr);

  void mark_as_escaped ();
  void on_unknown_fncall (const gcall *call, store_manager *mgr);

  bool escaped_p () const { return m_escaped; }
  bool touched_p () const { return m_touched; }

  bool redundant_p () const;
  bool empty_p () const { return m_map.elements () == 0; }

  void get_representative_path_vars (const region_model *model,
				     svalue_set *visited,
				     const region *base_reg,
				     const svalue *sval,
				     auto_vec<path_var> *out_pvs) const;

  const svalue *maybe_get_simple_value (store_manager *mgr) const;

  template <typename BindingVisitor>
  void for_each_binding (BindingVisitor &v)
  {
    for (map_t::iterator iter = m_map.begin (); iter != m_map.end (); ++iter)
      {
	const binding_key *key = (*iter).first;
	const svalue *&sval = (*iter).second;
	v.on_binding (key, sval);
      }
  }

  iterator_t begin () const { return m_map.begin (); }
  iterator_t end () const { return m_map.end (); }

  const binding_map &get_map () const { return m_map; }

private:
  const svalue *get_any_value (const binding_key *key) const;
  void get_overlapping_bindings (store_manager *mgr, const region *reg,
				 auto_vec<const binding_key *> *out);
  void bind_compound_sval (store_manager *mgr,
			   const region *reg,
			   const compound_svalue *compound_sval);
  void bind_key (const binding_key *key, const svalue *sval);

  const region *m_base_region;

  binding_map m_map;

  /* Has a pointer to this cluster "escaped" into a part of the program
     we don't know about (via a call to a function with an unknown body,
     or by being passed in as a pointer param of a "top-level" function call).
     Such regions could be overwritten when other such functions are called,
     even if the region is no longer reachable by pointers that we are
     tracking. */
  bool m_escaped;

  /* Has this cluster been written to via a symbolic binding?
     If so, then we don't know anything about unbound subregions,
     so we can't use initial_svalue, treat them as uninitialized, or
     inherit values from a parent region.  */
  bool m_touched;
};

/* The mapping from regions to svalues.
   This is actually expressed by subdividing into clusters, to better
   handle aliasing.  */

class store
{
public:
  typedef hash_map <const region *, binding_cluster *> cluster_map_t;

  store ();
  store (const store &other);
  ~store ();

  store &operator= (const store &other);

  bool operator== (const store &other) const;
  bool operator!= (const store &other) const
  {
    return !(*this == other);
  }

  hashval_t hash () const;

  void dump_to_pp (pretty_printer *pp, bool summarize, bool multiline,
		   store_manager *mgr) const;
  void dump (bool simple) const;
  void summarize_to_pp (pretty_printer *pp, bool simple) const;

  const svalue *get_direct_binding (store_manager *mgr, const region *reg);
  const svalue *get_default_binding (store_manager *mgr, const region *reg);
  const svalue *get_any_binding (store_manager *mgr, const region *reg) const;

  bool called_unknown_fn_p () const { return m_called_unknown_fn; }

  void set_value (store_manager *mgr, const region *lhs_reg,
		  const svalue *rhs_sval, enum binding_kind kind);
  void clobber_region (store_manager *mgr, const region *reg);
  void purge_region (store_manager *mgr, const region *reg);
  void zero_fill_region (store_manager *mgr, const region *reg);
  void mark_region_as_unknown (store_manager *mgr, const region *reg);

  const binding_cluster *get_cluster (const region *base_reg) const;
  binding_cluster *get_cluster (const region *base_reg);
  binding_cluster *get_or_create_cluster (const region *base_reg);
  void purge_cluster (const region *base_reg);

  template <typename T>
  void for_each_cluster (void (*cb) (const region *base_reg, T user_data),
			 T user_data) const
  {
    for (cluster_map_t::iterator iter = m_cluster_map.begin ();
	 iter != m_cluster_map.end (); ++iter)
      cb ((*iter).first, user_data);
  }

  static bool can_merge_p (const store *store_a, const store *store_b,
			   store *out_store, store_manager *mgr,
			   model_merger *merger);

  void mark_as_escaped (const region *base_reg);
  void on_unknown_fncall (const gcall *call, store_manager *mgr);
  bool escaped_p (const region *reg) const;

  void get_representative_path_vars (const region_model *model,
				     svalue_set *visited,
				     const svalue *sval,
				     auto_vec<path_var> *out_pvs) const;

  cluster_map_t::iterator begin () const { return m_cluster_map.begin (); }
  cluster_map_t::iterator end () const { return m_cluster_map.end (); }

  tristate eval_alias (const region *base_reg_a,
		       const region *base_reg_b) const;

  template <typename BindingVisitor>
  void for_each_binding (BindingVisitor &v)
  {
    for (cluster_map_t::iterator iter = m_cluster_map.begin ();
	 iter != m_cluster_map.end (); ++iter)
      (*iter).second->for_each_binding (v);
  }

  void canonicalize (store_manager *mgr);
  void loop_replay_fixup (const store *other_store,
			  region_model_manager *mgr);

private:
  void remove_overlapping_bindings (store_manager *mgr, const region *reg);
  tristate eval_alias_1 (const region *base_reg_a,
			 const region *base_reg_b) const;

  cluster_map_t m_cluster_map;

  /* If this is true, then unknown code has been called, and so
     any global variable that isn't currently modelled by the store
     has unknown state, rather than being in an "initial state".
     This is to avoid having to mark (and thus explicitly track)
     every global when an unknown function is called; instead, they
     can be tracked implicitly.  */
  bool m_called_unknown_fn;
};

/* A class responsible for owning and consolidating binding keys
   (both concrete and symbolic).
   Key instances are immutable as far as clients are concerned, so they
   are provided as "const" ptrs.  */

class store_manager
{
public:
  store_manager (region_model_manager *mgr) : m_mgr (mgr) {}

  /* binding consolidation.  */
  const concrete_binding *
  get_concrete_binding (bit_offset_t start_bit_offset,
			bit_offset_t size_in_bits,
			enum binding_kind kind);
  const symbolic_binding *
  get_symbolic_binding (const region *region,
			enum binding_kind kind);

  region_model_manager *get_svalue_manager () const
  {
    return m_mgr;
  }

  void log_stats (logger *logger, bool show_objs) const;

private:
  region_model_manager *m_mgr;
  consolidation_map<concrete_binding> m_concrete_binding_key_mgr;
  consolidation_map<symbolic_binding> m_symbolic_binding_key_mgr;
};

} // namespace ana

#endif /* GCC_ANALYZER_STORE_H */
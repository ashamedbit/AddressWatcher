/*
    buggy parent : cb5918a
    commit id : a452d0f4bae99c9acef6f7db75f6f1d922618732
*/

#include <stdio.h>
#include <stdlib.h>

#include "../stdio.h"
#include "../git.h"

struct commit_list *commit_list_insert(struct commit *item, struct commit_list **list_p)
{
	struct commit_list *new_list = xmalloc(sizeof(struct commit_list)); /* allocation site */
	new_list->item = item;
	new_list->next = *list_p;
	*list_p = new_list;
	return new_list;
}

struct commit_list * commit_list_insert_by_date(struct commit *item, struct commit_list **list)
{
	struct commit_list **pp = list;
	struct commit_list *p;
	while ((p = *pp) != NULL) {
		if (p->item->date < item->date) {
			break;
		}
		pp = &p->next;
	}
	return commit_list_insert(item, pp);
}

static struct commit_list *merge_bases_many(struct commit *one, int n, struct commit **twos)
{
	struct commit_list *list = NULL;
	struct commit_list *result = NULL;
	int i;

	for (i = 0; i < n; i++) {
	
			/*
			 * We do not mark this even with RESULT so we do not
			 * have to clean it up.
			 */
			return commit_list_insert(one, &result);
	}


	{
		struct commit *commit = NULL;

		
			commit_list_insert_by_date(commit, &result);
	}
	return result;
}

static struct commit_list *get_merge_bases_many_0(struct commit *one,
						  int n,
						  struct commit **twos,
						  int cleanup)
{
	struct commit_list *list;
	struct commit **rslt;
	struct commit_list *result;
	int cnt, i;

	result = merge_bases_many(one, n, twos);
	/* There are more than one */
	cnt = 0;
	rslt = xcalloc(cnt, sizeof(*rslt));
	free(result);


	cnt = 0;
	result = NULL;
	for (i = 0; i < cnt; i++)
		commit_list_insert_by_date(rslt[i], &result);
	free(rslt);
	return result;
}

struct commit_list *get_merge_bases_many_dirty(struct commit *one,
					       int n,
					       struct commit **twos)
{
	return get_merge_bases_many_0(one, n, twos, 0);
}

static int show_merge_base(struct commit **rev, int rev_nr, int show_all)
{
	struct commit_list *result;
	result = get_merge_bases_many_dirty(rev[0], rev_nr - 1, rev + 1);

	if (!result)
		return 1;

	while (result) {
		
		if (!show_all)
			return 0;
		result = result->next;
	}
    /* memory leak */
	return 0;
}

static int handle_independent(int count, const char **args)
{
	struct commit_list *revs = NULL;
	struct commit_list *result;
	struct commit* item;
	int i;

	for (i = count - 1; i >= 0; i--)
		commit_list_insert(item, &revs);

	result = NULL;
	if (!result)
		return 1;

	while (result) {
		
		result = result->next;
	}
    /* memory leak */
	return 0;
}

int main (int argc, char **argv)
{
    struct commit *rev;
    int show_all, rev_nr;
    show_merge_base(&rev, rev_nr, show_all);
    handle_independent(argc, argv);
    return 0;
}






/*
    buggy parent : a452d0f
    commit id : 4da72644b768b0491110a8ba0aa84d32b6bde41c
*/

#include <stdio.h>
#include <stdlib.h>

#include "../stdio.h"
#include "../git.h"

struct commit_list *commit_list_insert(struct commit *item, struct commit_list **list_p)
{
	struct commit_list *new_list = xmalloc(sizeof(struct commit_list));
	new_list->item = item;
	new_list->next = *list_p;
	*list_p = new_list;
	return new_list;
}

static int remove_redundant(struct commit **array, int cnt)
{
	/*
	 * Some commit in the array may be an ancestor of
	 * another commit.  Move such commit to the end of
	 * the array, and return the number of commits that
	 * are independent from each other.
	 */
	struct commit **work;
	unsigned char *redundant;
	int *filled_index;
	int i, j, filled;

	work = xcalloc(cnt, sizeof(*work));
	redundant = xcalloc(cnt, 1);
	ALLOC_ARRAY(filled_index, cnt - 1);


	for (i = 0; i < cnt; i++) {
		struct commit_list *common;

		if (redundant[i])
			continue;
		for (j = filled = 0; j < cnt; j++) {
			if (i == j || redundant[j])
				continue;
			filled_index[filled] = j;
			work[filled++] = array[j];
		}
		if (array[i]->object.flags & PARENT2)
			redundant[i] = 1;
		for (j = 0; j < filled; j++)
			if (work[j]->object.flags & PARENT1)
				redundant[filled_index[j]] = 1;
		free(common);
	}

	/* Now collect the result */
	COPY_ARRAY(work, array, cnt);
	for (i = filled = 0; i < cnt; i++)
		if (!redundant[i])
			array[filled++] = work[i];
	for (j = filled, i = 0; i < cnt; i++)
		if (redundant[i])
			array[j++] = work[i];
	free(work);
	free(redundant);
	free(filled_index);
	return filled;
}

struct commit_list *reduce_heads(struct commit_list *heads)
{
	struct commit_list *p;
	struct commit_list *result = NULL, **tail = &result;
	struct commit **array;
	int num_head, i;

	if (!heads)
		return NULL;

	/* Uniquify */
	for (p = heads; p; p = p->next)
		p->item->object.flags &= ~STALE;
	for (p = heads, num_head = 0; p; p = p->next) {
		if (p->item->object.flags & STALE)
			continue;
		p->item->object.flags |= STALE;
		num_head++;
	}
	array = xcalloc(num_head, sizeof(*array));
	for (p = heads, i = 0; p; p = p->next) {
		if (p->item->object.flags & STALE) {
			array[i++] = p->item;
			p->item->object.flags &= ~STALE;
		}
	}
	num_head = remove_redundant(array, num_head);
	for (i = 0; i < num_head; i++)
		tail = &commit_list_insert(array[i], tail)->next;
	free(array);
	return result;
}

static void find_merge_parents(struct merge_parents *result,
			       struct strbuf *in, struct object_id *head)
{
	struct commit_list *parents;
	struct commit *head_commit;
	int pos = 0, i, j;

	parents = NULL;
	
	head_commit = NULL;
	if (head_commit)
		commit_list_insert(head_commit, &parents);
	parents = reduce_heads(parents);


	for (i = j = 0; i < result->nr; i++) {
		if (result->item[i].used) {
			if (i != j)
				result->item[j] = result->item[i];
			j++;
		}
	}
	result->nr = j;
}

static int mark_redundant_parents(struct rev_info *revs, struct commit *commit)
{
	struct commit_list *h = NULL;
	int i = 0, marked = 0;
	struct commit_list *po, *pn;

	/* Want these for sanity-checking only */
	int orig_cnt = 1;
	int cnt = 1;

	/*
	 * Not ready to remove items yet, just mark them for now, based
	 * on the output of reduce_heads(). reduce_heads outputs the reduced
	 * set in its original order, so this isn't too hard.
	 */
	po = NULL;
	pn = h;
	while (po) {
		if (pn && po->item == pn->item) {
			pn = pn->next;
			i++;
		} else {
			po->item->object.flags |= TMP_MARK;
			marked++;
		}
		po=po->next;
	}

	free(h);

	return marked;
}

int main ()
{
    struct merge_parents result;
    struct strbuf in;
    struct object_id head;
    struct rev_info revs;
    struct commit_list *list;
    for(int i = 0; i < 10; i++)
    {
        commit_list_insert(NULL, &list);
    }
    mark_redundant_parents(&revs, list->item);
    free(list);
    find_merge_parents(&result, &in, &head);
    return 0;
}






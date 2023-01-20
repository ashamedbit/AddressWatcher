/*
    buggy parent :  7c11718 
    commit id : f4e45cb3eb6fad4570ff63eecb37bae8102992fc
*/

#include <stdio.h>
#include <stdlib.h>

#include "../stdio.h"
#include "../git.h"

struct commit *pop_commit(struct commit_list **stack)
{
	struct commit_list *top = *stack;
	struct commit *item = top ? top->item : NULL;

	if (top) {
		*stack = top->next;
		free(top);
	}
	return item;
}

int weight(void* x)
{
	return 10;
}

void free_commit_list(struct commit_list *list)
{
	while (list)
		pop_commit(&list);
}

struct commit_list *commit_list_insert(struct commit *item, struct commit_list **list_p)
{
	struct commit_list *new_list = xmalloc(sizeof(struct commit_list)); /* allocation site */
	new_list->item = item;
	new_list->next = *list_p;
	*list_p = new_list;
	return new_list;
}

static struct commit_list *best_bisection(struct commit_list *list, int nr)
{
	struct commit_list *p, *best;
	int best_distance = -1;

	best = list;
	for (p = list; p; p = p->next) {
		int distance;
		unsigned flags = p->item->object.flags;

		if (flags & TREESAME)
			continue;
		distance = weight(p);
		if (nr - distance < distance)
			distance = nr - distance;
		if (distance > best_distance) {
			best = p;
			best_distance = distance;
		}
	}

	return best;
}

static struct commit_list *best_bisection_sorted(struct commit_list *list, int nr)
{
	struct commit_list *p;
	struct commit_dist *array = xcalloc(nr, sizeof(*array));
	int cnt, i;

	for (p = list, cnt = 0; p; p = p->next) {
		int distance;
		unsigned flags = p->item->object.flags;

		if (flags & TREESAME)
			continue;
		distance = weight(p);
		if (nr - distance < distance)
			distance = nr - distance;
		array[cnt].commit = p->item;
		array[cnt].distance = distance;
		cnt++;
	}
	for (p = list, i = 0; i < cnt; i++) {
		struct object *obj = &(array[i].commit->object);
		p->item = array[i].commit;
		if (i < cnt - 1)
			p = p->next;
	}
	free_commit_list(p->next);
	p->next = NULL;
	free(array);
	return list;
}


static struct commit_list *do_find_bisection(struct commit_list *list,
					     int nr, int *weights,
					     int find_all)
{
	int n, counted;
	struct commit_list *p;

	counted = 0;



	if (weights[0] == 0)
		return NULL;
	return NULL;
}

void find_bisection(struct commit_list **commit_list, int *reaches,
		    int *all, int find_all)
{
	int nr, on_list;
	struct commit_list *list, *p, *best, *next, *last;
	int *weights;

	list = last;

	*all = nr;
	weights = malloc(100);

	/* Do the real work of finding bisection commit. */
	best = do_find_bisection(list, nr, weights, find_all);
	if (best) {
		if (!find_all)
			best->next = NULL;              /* memory leak */
		*reaches = weight(best);
	}
	free(weights);
	*commit_list = best;
}
int main()
{   
    struct commit_list *list;
    int reaches, all, find_all;
    for(int i = 0; i < 10; i++)
    {
        commit_list_insert(NULL, &list);
    }
    find_bisection(&list, &reaches, &all, find_all);
    free_commit_list(list);
    return 0;
}



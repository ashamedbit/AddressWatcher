/*
    commit id : cb7b29eb67772d08e2365ed07ede9d954d0344c1
*/

#include <stdio.h>
#include <stdlib.h>

#include "../stdio.h"
#include "../git.h"

/* Remember to update object flag allocation in object.h */
#define PARENT1		(1u<<16)
#define PARENT2		(1u<<17)
#define STALE		(1u<<18)
#define RESULT		(1u<<19)



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

	
	free(work);
	free(redundant);
	free(filled_index);
	return filled;
}

struct commit_list *commit_list_insert(struct commit *item, struct commit_list **list_p)
{
    struct commit_list *new_list = xmalloc(sizeof(struct commit_list));
    new_list->item = item;
    new_list->next = *list_p;
    *list_p = new_list;
    return new_list;
}

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


void free_commit_list(struct commit_list *list)
{
    
        free(list);
}

struct commit_list *reduce_heads(struct commit_list *heads)
{
	struct commit_list *p;
	struct commit_list *result = NULL, **tail = &result;
	struct commit **array;
	int num_head, i;

	if (!heads)
		return NULL;

	array = xcalloc(num_head, sizeof(*array)); /* allocation site */
	num_head = remove_redundant(array, num_head);
	for (i = 0; i < num_head; i++)
		tail = &commit_list_insert(array[i], tail)->next;
	                                            /* memory leak */
	return result;
}

int main()
{
    struct commit_list *list, *reduced_list;
    int reaches, all, find_all;
    for(int i = 0; i < 10; i++)
    {
        commit_list_insert(NULL, &list);
    }
    reduced_list = reduce_heads(list);

    free_commit_list(list);
    return 0;
}







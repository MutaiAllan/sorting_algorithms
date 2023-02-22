#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: Pointer to the head of a doubly-linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp;
	int node;

	temp = *list;
	temp = temp->next;

	for (i = temp; i != NULL; i = i->next)
	{
		node = i->n;
		j = i->prev;

		while ((j != NULL) && (j->n > node))
		{
			i->prev = j->prev;
			j->prev = i;
			j->next = i->next;

			if (i->next != NULL)
				i->next->prev = j;
			i->next = j;

			if (i->prev == NULL)
				*list = i;
			else
				i->prev->next = i;

			j = i->prev;
			print_list(*list);
		}
	}
}

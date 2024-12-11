#include "sort.h"
#include <stdio.h>

/**
* insertion_sort_list - Sorts a doubly linked list of integers
 *in ascending order
*                       using the Insertion sort algorithm.
* @list: Double pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !(*list) || !(*list)->next)
	return;

current = (*list)->next;

while (current)
{
	tmp = current;
	current = current->next;

	while (tmp->prev && tmp->n < tmp->prev->n)
	{
		listint_t *prev = tmp->prev;

		if (prev->prev)
			prev->prev->next = tmp;
		else
			*list = tmp;

		if (tmp->next)
			tmp->next->prev = prev;

		prev->next = tmp->next;
		tmp->next = prev;
		tmp->prev = prev->prev;
		prev->prev = tmp;

		print_list(*list);
	}
}
}

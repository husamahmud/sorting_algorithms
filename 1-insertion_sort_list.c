#include "sort.h"

/**
 * insertion_sort_list - Insertion Sort Algorithm.
 *
 * @list: Double pointer to hte head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *prev_node;
	int data;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		data = curr->n;
		prev_node = curr->prev;

		while (prev_node && prev_node->n > data)
		{
			swap_nodes(list, curr, prev_node);
			print_list(*list);
			prev_node = curr->prev;
		}
	}
}

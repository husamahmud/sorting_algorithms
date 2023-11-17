#include "sort.h"

void swap_nodes(listint_t **list, listint_t *curr, listint_t *prev_node);

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

	/* check for invalid input or lists wiht 0 or 1 nodes */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* iterate over the list starting from the second node */
	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		data = curr->n;
		prev_node = curr->prev;

		/* move the curr node backward till it reaches the correct position */
		while (prev_node && prev_node->n > data)
		{
			/* swap the curr node with its prev node */
			swap_nodes(list, curr, prev_node);
			print_list(*list);
			prev_node = curr->prev;
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Double pointer to the head of the list
 * @curr: Node to be swapped.
 * @prev_node: Previous node of the node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *curr, listint_t *prev_node)
{
	prev_node->next = curr->next;
	if (curr->next)
		curr->next->prev = prev_node;

	curr->next = prev_node;
	curr->prev = prev_node->prev;
	prev_node->prev = curr;

	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
}

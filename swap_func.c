#include "sort.h"

/**
 * swap - Swaps two values of two integers.
 *
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
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

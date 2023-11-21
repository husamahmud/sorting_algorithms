#include "sort.h"

void swap(int *x, int *y);

/**
 * check_swiftdown - checks the heap property and swaps if necessary
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 * @size_init: original size of the array
 * @root: index of the root of the tree
 */
void check_swiftdown(int *array, size_t size_init, size_t size, size_t root)
{
	size_t left_child, right_child;
	int left_child_val, right_child_val;

	left_child = root * 2 + 1;
	right_child = left_child + 1;
	left_child_val = array[left_child];
	right_child_val = array[right_child];

	if (((left_child < size) && (right_child < size) &&
	     (left_child_val >= right_child_val && left_child_val > array[root])) ||
	    ((left_child == size - 1) && left_child_val > array[root]))
	{
		swap(&array[root], &array[left_child]);
		print_array(array, size_init);
	} else if ((left_child < size) && (right_child < size) &&
				(right_child_val > left_child_val &&
				right_child_val > array[root]))
	{
		swap(&array[root], &array[right_child]);
		print_array(array, size_init);
	}

	if (left_child < size - 1)
		check_swiftdown(array, size_init, size, left_child);
	if (right_child < size - 1)
		check_swiftdown(array, size_init, size, right_child);
}

/**
 * heap_sort - Heap sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;

	if (!array)
		return;

	for (i = 0; i < size / 2; i++)
	{
		check_swiftdown(array, size_init, size, size / 2 - 1 - i);
	}

	for (i = 0; i < size_init - 1; i++)
	{
		swap(&array[0], &array[size - 1 - i]);
		print_array(array, size_init);
		check_swiftdown(array, size_init, size - i - 1, 0);
	}
}

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

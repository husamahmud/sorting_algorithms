#include "sort.h"

void swap(int *x, int *y);

/**
 * sift_down - Restores the heap property by sifting down the element at the
 * given index.
 *
 * @array: Pointer to the array.
 * @start: The start index of the sub-heap.
 * @end: The end index of the sub-heap.
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while (root * 2 + 1 <= end)
	{
		size_t child = root * 2 + 1;
		size_t swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);

		root = swap_idx;
	}
}

/**
 * heap_sort - Heap Sort Algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, i - 1, size - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		sift_down(array, 0, i - 1, size);
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

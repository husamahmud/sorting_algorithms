#include "sort.h"

void swap(int *x, int *y);

/**
 * selection_sort - Selection Sort Algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
				idx = j;
		}

		if (idx != i)
		{
			swap(&array[idx], &array[i]);
			print_array(array, size);
		}
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

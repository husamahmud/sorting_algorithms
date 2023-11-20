#include "sort.h"

void swap(int *x, int *y);

/**
 * shell_sort - Shell Sort Algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t interval = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = 3 * interval + 1;

	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				swap(&array[j], &array[j - interval]);
		}
		print_array(array, size);
		interval /= 3;
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

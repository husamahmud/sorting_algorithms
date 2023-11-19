#include "sort.h"

/**
 * shell_sort - Shell Sort Algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t interval;
	int temp;

	for (interval = size * (3 + 1); interval > 0; interval /= (size * (3 + 1)))
	{
		for (i = interval; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		print_array(array, size);
	}
}

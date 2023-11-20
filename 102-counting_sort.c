#include "sort.h"

/**
 * counting_sort - Counting sort Algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *sorted;
	size_t max;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int) max)
			max = array[i];
	}

	count = (int *) malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;


	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	sorted = (int *) malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = sorted[i];
	}

	free(count);
	free(sorted);
}

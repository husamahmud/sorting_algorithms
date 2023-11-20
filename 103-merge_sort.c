#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 *
 * @array: A pointer to the array where the merged result will be stored.
 * @left: A pointer to the left subarray.
 * @left_size: The number of elements in the left subarray.
 * @right: A pointer to the right subarray.
 * @right_size: The number of elements in the right subarray.
 */
void
merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	int *temp = (int *) malloc((left_size + right_size) * sizeof(int));
	size_t i = 0, j = 0, k = 0;
	size_t idx;

	if (temp == NULL)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		} else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		temp[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		temp[k] = right[j];
		j++;
		k++;
	}

	for (idx = 0; idx < left_size + right_size; idx++)
		array[idx] = temp[idx];

	printf("[Done]: ");
	print_array(array, right_size + left_size);

	free(temp);
}

/**
 * merge_sort - Merge Sort Algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid = size / 2;

	if (size <= 1)
		return;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);

	left = array;
	right = array + mid;

	merge(array, left, mid, right, size - mid);
}

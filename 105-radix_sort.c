#include "sort.h"

/**
 * max - get the maximum element in the array.
 * @array: array to find the maximum element from.
 * @size: size of the array.
 *
 * Return: The maximum element in the array.
 */
size_t max(int *array, size_t size)
{
	size_t i;
	int max;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort2 - Perform Counting Sort on the array based on a specific num
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 * @digit: The exponent to split and control over the digit of each element.
 */
void counting_sort2(int *array, size_t size, int digit)
{
	size_t i;
	int *sorted;
	int freq[10] = {0};

	if (!array || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;

	for (i = 0; i < size; i++)
		freq[array[i] / digit % 10] += 1;

	for (i = 1; i < 10; i++)
		freq[i] += freq[i - 1];

	for (i = size - 1; (int) i >= 0; i--)
		sorted[--freq[array[i] / digit % 10]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	print_array(array, size);
	free(sorted);
}

/**
 * radix_sort - Perform Radix Sort on the array.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	size_t digit, maxNum;

	if (!array || size < 2)
		return;

	maxNum = max(array, size);
	for (digit = 1; (maxNum / digit) > 0; digit *= 10)
	{
		counting_sort2(array, size, digit);
	}
}

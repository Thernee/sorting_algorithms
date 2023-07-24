#include "sort.h"

/**
 * selection_sort - Implementation of a selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t j, last_sorted = 0;
	size_t curr_min_idx;
	int curr_min;

	if (!array || !size)
		return;

	while (last_sorted < size - 1)
	{
		curr_min_idx = last_sorted;

		for (j = last_sorted + 1; j < size; j++)
		{
			if (array[j] < array[curr_min_idx])
			{
				curr_min_idx = j;
			}
		}

		if (curr_min_idx != last_sorted)
		{
			curr_min = array[curr_min_idx];
			array[curr_min_idx] = array[last_sorted];
			array[last_sorted] = curr_min;
			print_array(array, size);
		}

		last_sorted++;
	}
}

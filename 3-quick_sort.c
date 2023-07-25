#include "sort.h"

/**
 * quick_sort - implements a quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_recursive(array, 0, size - 1, size);
}

/**
 * swap - swaps 2 elements
 * @a: first element to swap
 * @b: second element to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - splits given array into partition then sorts
 * @array: array to sort
 * @left: first index
 * @right: last index
 * @size: size of array
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot, idx, j;


	pivot = array[right];
	idx = left;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			if (idx != j)
			{
				swap(&array[idx], &array[j]);
				print_array(array, size);
			}
			idx++;
		}
	}

	if (idx != right)
	{
		swap(&array[idx], &array[right]);
		print_array(array, size);
	}

	return (idx);
}

/**
 * sort_recursive - recursively sorts given algorithm
 * @array: array to sort
 * @left: first index
 * @right: last index
 * @size: size of array
 */
void sort_recursive(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = lomuto_partition(array, left, right, size);
		sort_recursive(array, left, pivot - 1, size);
		sort_recursive(array, pivot + 1, right, size);
	}
}


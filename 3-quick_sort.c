#include "sort.h"

/**
 * quick_sort - implements a quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
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


	pivot = arr[right];
	idx = left - 1;

	for (j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			idx++;
			if (idx != j)
			{
				swap(&arr[idx], &arr[j]);
				print_array(arr, size);
			}
		}
	}

	/*placing pivot in the right spot*/
	swap(&arr[idx + 1], &arr[right]);
	print_array(arr, size);

	return (idx + 1);
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

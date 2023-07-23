#include "sort.h"

/**
 * bubble_sort - sorts integers in ascending order
 *
 * @array: The array of integers to be sorted
 * @size: Size of the given array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;
	bool swap = false;

	while (i < size)
	{
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				swap = true;
				print_array(array, size);
			}
		}
		if (swap == false)
			exit(0);
		swap = false;

		i++;
	}
}
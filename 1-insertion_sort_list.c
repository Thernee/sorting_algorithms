#include "sort.h"

/**
 * insertion_sort_list - Implements the insertion sort algorithm
 *
 * @list: pointer to the list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *holder, *head, *unsorted, *ahead, *behind, *current;

	if (!list || !*list || !(*list)->next)
		return;

	head = *list;
	unsorted = head->next;

	while (unsorted)
	{
		holder = unsorted;
		while (holder->prev && holder->n < holder->prev->n)
		{
			current = holder;
			behind = holder->prev;
			ahead = holder->next;
			current->prev = behind->prev;
			current->next = behind;

			behind->prev = current;
			behind->next = ahead;

			if (current->prev)
				current->prev->next = current;

			if (behind == head)
				*list = current;
			if (ahead)
				ahead->prev = behind;

			print_list(*list);
			holder = behind->prev;
		}
		unsorted = unsorted->next;
	}
}


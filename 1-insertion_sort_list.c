#include "sort.h"

/**
 * insertion_sort_list - Implements the insertion sort algorithm
 *
 * @list: pointer to the list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *holder, *temp, *sorted, *unsorted, *head;

	if (!list || !*list)
		return;

	head = sorted = *list;
	if (sorted->next == NULL)
		return;
	unsorted = sorted->next;

	while (unsorted)
	{
		if (sorted->n > unsorted->n)
		{
			holder = unsorted;
			unsorted = unsorted->next;
			if (sorted->prev)
				temp = sorted->prev;
			swap_node(sorted, holder);
			print_list(head);

			while (temp && temp->prev && temp->n > holder->n)
			{
				swap_node(temp, holder);
				print_list(head);
				temp = holder->prev;
			}

			if (!holder->prev)
				head = holder;
		}
		else
		{
			sorted = sorted->next;
			if (sorted)
				unsorted = sorted->next;
		}
	}
	*list = holder;
}
/**
 * swap_node - swaps 2 nodes of a doubly linked list
 *
 * @node1: first node to swap
 * @node2: second node to swap
 * Return: nothing
 */
void swap_node(listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev = node1->prev;
	listint_t *temp_next = node2->next;

	if (temp_prev)
		temp_prev->next = node2;
	if (temp_next)
		temp_next->prev = node1;

	node1->prev = node2;
	node1->next = temp_next;
	node2->prev = temp_prev;
	node2->next = node1;
}

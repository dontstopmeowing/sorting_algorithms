#include "sort.h"

/**
 * swap - function that swaps a node
 *
 * @prev: points to previous node.
 * @current: points to current node (the one you're at).
 *
 */
void swap(listint_t *prev, listint_t *current)
{
	current->prev = prev->prev;
	prev->next = current->next;
	prev->prev = current;
	current->next = prev;

	if (current->prev)
		current->prev->next = current;
	if (prev->next)
		prev->next->prev = prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 *
 * @list: list to sort.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *first;
	size_t i, size = 0;

	if (list == NULL)
		return;

	first = *list;
	current = *list;

	for (i = 0; current != NULL; i++)
	{
		size++;
		for (i = 0; current->prev != NULL; i++)
		{
			if (current->n < current->prev->n)
			{
				swap(current->prev, current);

				if (current->prev == NULL)
				{
					first = current;
					*list = first;
				}
				print_list(*list);
			}
			else
				break;
		}
		for (i = 0; i < size; i++)
		{
			if (i == 0)
				current = first->next;
			else
				current = current->next;
		}
	}
}

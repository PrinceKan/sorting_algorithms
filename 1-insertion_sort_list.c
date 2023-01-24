#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *present, *ordered;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ordered = *list;
	present = (*list)->next;

	while (present != NULL)
	{
		if (ordered != NULL &&  ordered->n > present->n)
		{

			present = swap(&present, &ordered);
			ordered = present->prev;
			if (ordered == NULL)
				*list = present;
			print_list(*list);

			while (ordered != NULL && ordered->n > present->n)
			{
				present = swap(&present, &ordered);
				ordered = present->prev;
				if (ordered == NULL)
					*list = present;
				print_list(*list);
			}
		}
		else
		{
			ordered = present;
			present = ordered->next;
		}
	}
}


/**
 * swap - Swaps the numbers in the array to put them in order
 * @present: Pointer to a pointer to a node in the linked list
 * @ordered: Pointer to a pointer to a node in the linked list
 * Return: A pointer to the current node.
 */
listint_t *swap(listint_t **present, listint_t **ordered)
{
	listint_t *tmp;

	tmp = (*present)->next;
	if (*ordered != NULL)
		(*ordered)->next = tmp;
	if (tmp != NULL)
		tmp->prev = *ordered;
	if (*present != NULL)
	{
		(*present)->next = *ordered;
		(*present)->prev = (*ordered)->prev;
	}
	if ((*ordered)->prev != NULL)
		(*ordered)->prev->next = *present;
	((*ordered)->prev) = *present;

	return (*present);
}

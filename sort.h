#ifndef SORT_ALGO_H
#define SORT_ALGO_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);
listint_t *swap(listint_t **present, listint_t **ordered);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void sort(int *array, size_t onset, size_t size, size_t);
int inspect(int *array, size_t onset, size_t finish);
int switcher(int *, size_t, size_t, size_t);

#endif

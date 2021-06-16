#ifndef SORT_H
#define SORT_H

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

/**********/
void swap(int *a, int *b);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
/* quick sprt*/
void quick_sort(int *array, size_t size);
void QuickSort(int *array, int low, size_t size, int high);
size_t Partition(int *array, int low, size_t size, int high);

void shell_sort(int *array, size_t size);

/*test functions*/
void insertion_sort(listint_t **list);
void swap_node(listint_t *curr, listint_t **list);

#endif

#include "sort.h"
/**
 * swap_node - function that swap nodes
 * @curr: node to swap
 * @list: a linked list
 */
void swap_node(listint_t *curr, listint_t **list)
{
	listint_t *tmp = NULL, *aux = NULL;

	tmp = curr->prev;

	if (curr->next == NULL && tmp->prev == NULL)
	{/* list of 2 elemnets*/
		curr->prev = NULL;
		curr->next = tmp;
		tmp->prev = curr;
		tmp->next = NULL;
		*list = curr;
	}
	else if (curr->next == NULL)
	{/* swap - at the end */
		aux = curr->prev->prev;
		aux->next = curr;
		curr->prev = aux;
		curr->next = tmp;
		tmp->prev = curr;
		tmp->next = NULL;
	}
	else if (curr->prev->prev != NULL)
	{/* swap - in the middel */
		aux = curr->prev->prev;
		curr->next->prev = curr->prev;
		curr->prev->next = curr->next;
		tmp->prev = curr;
		curr->next = tmp;
		curr->prev = aux;
		aux->next = curr;
	}
	else
	{/* swap - at the beginning */
		curr->next->prev = curr->prev;
		curr->prev->next = curr->next;
		curr->prev = NULL;
		curr->next = tmp;
		tmp->prev = curr;
		*list = curr;
	}
}
/**
 * insertion_sort_list - function that sorts a doubly
 * linked list of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *to_insert_node = NULL;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}
	curr = *list;
	while (curr->next)
	{
		if ((curr->prev) && (curr->n < curr->prev->n))
		{
			to_insert_node = curr;
			while ((to_insert_node->prev) &&
			(to_insert_node->n < to_insert_node->prev->n))
			{
				swap_node(to_insert_node, list);
				print_list(*list);
			}
		}
		curr = curr->next;
	}
	to_insert_node = curr;
	while ((to_insert_node->prev != NULL) &&
	(to_insert_node->n < to_insert_node->prev->n))
	{
		swap_node(to_insert_node, list);
		print_list(*list);
	}
}

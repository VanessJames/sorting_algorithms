#include "sort.h"


/**
 * swap - swap list elements
 * @temp: current element to change
 * @list: linked list
 */
void swap(listint_t **temp, listint_t **list)
{
	(*temp)->prev->next = (*temp)->next;
	if ((*temp)->next != NULL)
		(*temp)->next->prev = (*temp)->prev;
	(*temp)->next = (*temp)->prev;
	(*temp)->prev = (*temp)->prev->prev;
	(*temp)->next->prev = *temp;
	if ((*temp)->prev != NULL)
		(*temp)->prev->next = *temp;
	else
		*list = *temp;

}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to doubly linked list of integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current_node, *next_node;

	if (list == NULL || *list == NULL)
		return;

	current_node = *list;

	while (current_node)
	{
		next_node = current_node->next;
		temp = current_node;

		while (temp->prev && temp->n < temp->prev->n)
		{
			swap(&temp, list);
			print_list(*list);
		}
		current_node = next_node;
	}
}

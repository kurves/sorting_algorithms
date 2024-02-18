#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the head of the doubly linked list
 * Description: algrorithm to sort list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;
		while (prev_node != NULL && prev_node->n > current->n)
		{
			if (prev_node->prev != NULL)
			{
				prev_node->prev->next = current;
			}
			if (current->next != NULL)
			{
				current->next->prev = prev_node;
			}
			prev_node->next = current->next;
			current->prev = prev_node->prev;
			current->next = prev_node;
			prev_node->prev = current;
			if (current->prev == NULL)
			{
				*list = current;
			}
			print_list(*list);
			prev_node = current->prev;
		}
		current = next_node;
	}
}

#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * @list: Double pointer to the head of the linked list
 * Description: funtion to sort doubly liked list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start;
	listint_t *end;       
	
	start = NULL;
	end = NULL;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	start  = *list;
	end = (*list)->next;

	while(start != end)
	{
		swapped = 0;
		for (; end != NULL; end = end->next)
		{
			if (end->prev->n > end->n)
			{
				printf("%d <=> %d\n", end->prev->n, end->n);
				swap_nodes(list, end->prev, end);
				start = end;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = 0;
		for (end = end->prev; end != start; end = end->prev)
		{
			if (end->next->n < end->n)
			{
				printf("%d <=> %d\n", end->n, end->next->n);
				swap_nodes(list, end, end->next);
				end = end->prev;
				swapped = 1;
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node to swap
 * @b: Second node to swap
 * @list: Double pointer to the head of the linked list
 * Description: function to swap nodes
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{

	if (*list == NULL || node1 == NULL || node2 == NULL)
	{
		return;
	}
	if (*list == node1)
	{
		*list = node2;
	}
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}


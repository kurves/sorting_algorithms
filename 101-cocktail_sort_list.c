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
				print_list(*list);
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
				print_list(*list);
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
	listint_t *temp;

        temp = node1->next;

	if (*list == NULL || node1 == NULL || node2 == NULL)
	{
		return;
	}
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	if (node1 == *list)
	{
		*list = node2
	}
	else if (node2 == *list)
	{
		*list = node1;
	}
	node1->next = node2->next;
	node2->next = temp;
	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;
}

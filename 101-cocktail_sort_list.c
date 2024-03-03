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
	swapped = 1;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	while(swapped)
        {
                swapped = 0;
                start = *list;
		while(start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			start = start->next;
		}
		end = start;
		if (!swapped)
		{
			break;
		}
		while (end->prev != start)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, end, end->prev);
				swapped = 1;
				print_list(*list);
			}
			end = end->prev;
		}
		start = end;
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
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

        temp = node1->next;

	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	if (node2->next)
	{
		node2->next->prev = node1;
	}
	if (node1 == *head)
	{
		*head = node2;
	}
	else if (node2 == *head)
	{
		*head = node1;
	}
	node1->next = node2->next;
	node2->next = temp;
	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;
}

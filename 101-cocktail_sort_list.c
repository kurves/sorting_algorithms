#include "sort.h"

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
				swap_nodes(start, start->next, list);
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = 0;
		end = start;
		for (; start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(start->prev, start, list);
				swapped = 1;
			}
		}
	}while (swapped);
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
	if (a->next == b)
	{
		a->next = b->next;
		b->prev = a->prev;
		a->prev = b;
		b->next = a;
	}
	else
	{
		listint_t *temp = a->prev;
		a->prev = b->prev;
		b->prev = temp;
		temp = a->next;
		a->next = b->next;
		b->next = temp;
	}
	if (a->prev == NULL)
	{
		*list = a;
	}
	else if (b->prev == NULL)
	{
		*list = b;
	}
}

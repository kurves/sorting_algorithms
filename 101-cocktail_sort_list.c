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
	swapped = 1;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	do
	{
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
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
		for (end = start; end->prev != NULL; end = end->prev)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(end->prev, end, list);
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
void swap_nodes(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->prev != NULL)
	{
		a->prev->next = b;
	}
	if (b->next != NULL)
	{
		b->next->prev = a;
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

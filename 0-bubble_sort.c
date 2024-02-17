#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble-sort - sorting algoritm
 * @array: array of integers
 * @size: size of array
 * Description: algorithm to sort list and array contents
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	listint_t *head, *current;
	
	head = NULL;
	current = NULL;
	
	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		current = malloc(sizeof(listint_t));
		if (current == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		current->n = array[i];
		current->prev = NULL;
		current->next = head;
		if (head != NULL)
		{
			head->prev = current;
			head = current;
		}
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					current = head;
					while (current->next != NULL)
					{
						if (current->n == array[j])
						{
							current->n = array[j + 1];
						}
						else if (current->n == array[j + 1])
						{
							current->n = array[j];
						}
						current = current->next;
					}
					printf("Swap elements: ");
					print_array(array, size);
				}
			}
		}
		while (head != NULL)
		{
			current = head->next;
			free(head);
			head = current;
		}
}

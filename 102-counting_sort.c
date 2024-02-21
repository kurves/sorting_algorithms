#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers
 * @array: Array of integers to be sorted
 * @size: Size of the array
 * Description: sorts an array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *temp;
	int *count;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
	{
		return;
	}
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	for (i = 0; i <= max; i++)
	{
		printf("%d", count[i]);
	}
	j = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[j++] = i;
			count[i]--;
		}
	}	
	free(count);
}

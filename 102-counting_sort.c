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
	int *count;
	size_t j;
	size_t i;
	size_t max_size_t;

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
	max_size_t = (size_t)max;
	count = malloc((max_size_t + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	printf("Counting array:\n");
	for (i = 0; i <= max_size_t; i++)
	{
		printf("%d\n", count[i]);
	}
	j = 0;
	for (i = 0; i <= max_size_t; i++)
	{
		while (count[i] > 0)
		{
			array[j++] = i;
			count[i]--;
		}
	}
	free(count);
}

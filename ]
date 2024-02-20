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
	int i;

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
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}
	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	printf("Counting array:\n");
	for (i = 0; i <= max; i++)
	{
		printf("%d: %d\n", i, count[i]);
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

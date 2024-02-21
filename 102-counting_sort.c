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
	for (i = 0; i <= max_size_t; i++)
	{
		printf("%d", count[i]);
	}
	for (i = 1; i <= max_size_t; i++)
	{
		count[i] += count[i - 1];
	}
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		free(count);
		return;
	}
	j = size - 1; 
	for (i = max_size_t; i <= max_size_t; i--)
	{
		while (count[i] > 0)
		{
			temp[j--] = i;
			count[i]--;
		}
	}
	free(temp);
	free(count);
}

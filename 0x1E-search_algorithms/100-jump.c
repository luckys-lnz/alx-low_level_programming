#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array
 *               of integers using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index where value is located, else -1.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, start, end, i;

	if (array == NULL || size == 0)
		return (-1);

	step = (size_t)sqrt(size);
	prev = 0;

	/* Finding the block where value is present */
	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
	}

	/* Adjust the start and end of the block */
	start = prev - step;
	end = (prev < size) ? prev : size;

	printf("Value found between indexes [%lu] and [%lu]\n", start, end);

	/* Linear search within the block */
	for (i = start; i < end; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}


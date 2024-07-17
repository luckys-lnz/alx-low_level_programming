#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array
 *		of integers using the Jump search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: index where value is located, else -1
 */

int jump_search(int *array, size_t size, int value)
{
	/* Block size to jump */
	size_t step = sqrt(size);
	size_t prev = 0;
	size_t start;
	size_t  end;
	size_t i;

	if (array == NULL)
		return (-1);

	while (prev < size && array[prev] < value)
	{
		/* finding the block where value is present */
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
	}
	start = (prev >=  step) ? prev - step : 0;
	end = (prev < size) ? prev : size;
	printf("Value found between indexes [%lu] and [%lu]\n", start, end - 1);

	for (i = start; i < end; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}


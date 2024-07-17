#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 *                        of integers using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: First index where value is located, else -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	if (array == NULL || size == 0)
		return (-1);

	/* while the value is within range,loop low and high */
	while (low <= high && value >= array[low] && value <= array[high])
	{
		if (low == high)
		{
			if (array[low] == value)
				return (low);
			return (-1);
		}

		pos = low + (((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		/* if value is bigger, ignore the left side */
		if (array[pos] == value)
			return (pos);

		/* if smaller, ignore right side */
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	/* out of range if value > than last item in list */
	if (value > array[high])
		printf("Value checked array[%lu] is out of range\n", high + 1);

	return (-1);
}


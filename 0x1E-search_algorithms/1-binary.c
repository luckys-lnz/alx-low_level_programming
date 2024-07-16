#include "search_algos.h"

/**
 * binary_search - Searches for a value in sorted array of intergers
 *
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: index where value is located, else -1
 */

int binary_search(int *array, size_t size, int value)
{

	size_t Left = 0;
	size_t Right = size - 1;
	size_t mid;
	size_t i;

	if (array == NULL)
		return (-1);

	while (Left <= Right)
	{
		printf("Searching in array: ");
		for (i = Left; i <= Right; i++)
		{
			printf("%d", array[i]);
			if (i < Right)
				printf(", ");
		}
		printf("\n");
		mid = (Left + Right) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			Left = mid + 1;
		else
			Right = mid - 1;
	}
	return (-1);
}

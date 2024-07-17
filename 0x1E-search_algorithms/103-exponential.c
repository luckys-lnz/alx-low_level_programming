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

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using exponential search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 *              Uses powers of 2 as exponential ranges to search in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t left;
	size_t right;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	/* Find range for binary search by repeated doubling */
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	left = bound / 2;
	right = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	/* Call binary search for the found range */
	return (binary_search(array + left, right - left + 1, value) + left);
}


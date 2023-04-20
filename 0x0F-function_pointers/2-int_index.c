#include "function_pointers.h"

/**
 * int_index - function that searches for an integer.
 *
 * @array: my array.
 * @size: array size;
 * @cmp: function to check every element.
 *
 * Return: index of first match element in the array.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (size <= 0 || array == NULL || cmp == NULL)
		return (-1);

	for (x = 0 ; x < size ; x++)
	{
		if (cmp(array[x]))
			return (x);
	}

	return (-1);
}

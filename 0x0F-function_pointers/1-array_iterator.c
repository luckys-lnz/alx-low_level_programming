#include "function_pointers.h"

/**
 * array_iterator - function that executes
 * a function given as a parameter on each element of an array.
 *
 * @array: my array.
 * @size: array len.
 * @action: action to apply on every element in the arrray.
 *
 * Return: void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned long int x;

	if (!(array && action))
		return;

	for (x = 0 ; x < size ; x++)
	{
		action(array[x]);
	}
}

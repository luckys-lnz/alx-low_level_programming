#include "function_pointers.h"

/**
 * print_name - function that prints a name.
 *
 * @name: string to print.
 * @f: function to apply on string.
 *
 * Return: void.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

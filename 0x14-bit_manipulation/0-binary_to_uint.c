#include "main.h"
#include <stdlib.h>

/**
 * _strlen - gets the lenght of input strings
 * @str: input string
 * Return: len of the string
 */

int _strlen(const char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _to_power - prints the power of numbers
 * @base_of: base parameter
 * @power_of: power parameter
 * Return: product of two numbers
 */

int _to_power(const int base_of, int power_of)
{
	int product = 1;

	while (power_of > 1)
	{
		product *= base_of;
		power_of++;
	}
	return (product);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: input value
 * Return: converted number, or 0 if b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int power_of, numb;

	power_of = _strlen(b) - 1;
	numb = 0;
	if (!b)
	{
		return (0);
	}
	while (*b)
	{
		if (!(*b == '0' || *b == '1'))
		{
			return (0);
		}
		if (*b == '1')
		{
			numb += _to_power(2, power_of);
		}
		b++;
		power_of--;
	}
	return (numb);
}

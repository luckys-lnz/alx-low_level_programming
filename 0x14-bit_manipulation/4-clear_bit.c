#include "main.h"

/**
 * _to_power - powers a number b to the p's power
 * @base: base inupt
 * @power: power
 * Return: return b to the power of a
 */

unsigned long int _to_power(int base, int power)
{
	unsigned long int j = 1;

	while (power)
	{
		j *= base;
		power--;
	}
	return (j);
}

/**
 * clear_bit - sets bit to zero at index index
 * @n: input integer
 * @index: returns the value of a bit at a given index
 * Return: 1 for ssucess -1 for failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int t;

	if (index > sizeof(n) * 8 - 1)
	{
		return (-1);
	}
	t = _to_power(2, index);
	*n = (*n & t) ? *n ^ t : *n;
	return (1);

}

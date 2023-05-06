#include "main.h"

/**
 * flip_bits - flips binary numbers
 * to get from one number to another
 * @n: first input integer
 * @m: second input integer
 * Return: the number of bits you would need to
 * flip to get from one number to another
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int j = n ^ m;
	unsigned int flip_numb = 0;


	while (j)
	{
		if (1 & j)
		{
			flip_numb++;
		}
		j = j >> 1;
	}
	return (flip_numb);
}

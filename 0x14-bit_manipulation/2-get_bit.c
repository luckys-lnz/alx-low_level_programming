#include "main.h"
/**
 * get_bit - gets the power of a number
 * @n: first input integer
 * @index: second input integer
 * Return: return b to the power of a
 */
int get_bit(unsigned long int n, unsigned int index)
{

unsigned long int mask = 1UL << index;
if (index >= sizeof(unsigned long int) * 8)
return (-1);  /* Error: index out of range*/
if ((n & mask) != 0)
return (1);  /* Bit is set (1)*/
else
return (0);  /* Bit is not set (0)*/
}

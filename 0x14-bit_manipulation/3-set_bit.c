#include "main.h"
/**
 * set_bit - Set bit to a given index
 * @index: position bit
 * @n: original value
 * Return: return b to the power of a
 */
int set_bit(unsigned long int *n, unsigned int index)
{

unsigned long int mask;
unsigned int i;
if (index >= sizeof(unsigned long int) * 8)
return (-1);  /* Error: index out of range*/
mask = 1UL;
for (i = 0; i < index; i++)
{
mask <<= 1;
}
*n |= mask;
return (1);
}

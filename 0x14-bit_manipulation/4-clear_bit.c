#include "main.h"

/**
 * clear_bit - clear bits at index
 * @index : starting bit
 * @n : holds the value
 * Return: Always 1
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
/* Declare the variable 'mask' of type unsigned long int */
unsigned long int mask;
if (index >= sizeof(unsigned long int) * 8) /*converts byte to bit*/
return (-1); /*error out of range*/
/* Create a mask with the bit at the given index set to 0 and all other bits set to 1 */
mask = ~(1UL << index);
/* Clear the bit at the specified index in the value pointed to by 'n' */
*n &= mask;
return (1);
}

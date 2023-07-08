#include "main.h"
/**
 * flip_bits - flip bits
 * @m : point 1 input
 * @n : point 2 input
 *Return: 0
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{

/* Calculate the XOR of n and m to get the differing bits */
unsigned long int xor_result = n ^ m;
/* Variable to store the count of differing bits */
unsigned int count = 0;
/* Iterate until xor_result becomes 0 */
while (xor_result)
{
/* Increment count if the least significant bit of xor_result is set */
count += xor_result & 1;
/* Right-shift xor_result by 1 position to move to the next bit */
xor_result >>= 1;
}
/* Return the count, representing the number of differing bits */
return (count);
}

#include "main.h"
/**
 * print_binary - Converts from binary to unsigned integer.
 * @n: A pointer to the bit string.
 *
 * Return: The unsigned integer (success) & 0 (fails).
 */
void print_binary(unsigned long int n)
{

unsigned long int mask;
int leading_zeros;

if (n == 0)
{
_putchar('0');
return;
}
mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
leading_zeros = 1;
while (mask > 0)
{
if ((n & mask) != 0)
{
leading_zeros = 0;
_putchar('1');
}
else if (!leading_zeros)
{
_putchar('0');
}
mask >>= 1;
}
}


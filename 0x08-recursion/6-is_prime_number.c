#include "main.h"

/**
 * prym - checks to see if number is prime
 * @a:int
 * @b:int
 * Return:int
 */
int prym(int a, int b)
{
	if (b < 2 || b % a == 0)
		return (0);
	else if (a > b / 2)
		return (1);
	else
		return (prym(a + 1, b));
}

/**
 * is_prime_number - states if number is prime
 * @n:int
 * Return:int
 */
int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	return (prym(2, n));
}

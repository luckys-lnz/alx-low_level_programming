#include "main.h"

/*
 * Description - this is a version With Debug Option, this won't work
 *		with the checker copy go to the readme and click
 *		checker version that one will work with the checker.
*/

/**
 * debug_1 - print debug statements
 *
 * @n: value of n
 * @length: length of n
 * @bit_m: bit_m of n
 *
 * Return: nothing
*/
void debug_1(unsigned long int n, int length, unsigned long int mask)
{
	printf("Length of %lu (n) is %i ", n, (length + 1));
	printf("and bit_m (original value 1) ");
	printf("is %lu based ", bit_m);
	printf("on [length of n - 1] == %i.\n\n", length);
}


/**
 * debug_2 - print debug statements
 *
 * @n: value of n
 * @bit_m: bit_m of n
 *
 * Return: nothing
*/
void debug_2(unsigned long int n, unsigned long int bit_m)
{
	printf("Value of n is %lu, ", n);
	printf("value of bit_m is %lu and ", bit_m);
	printf("value of [n & bit_m] is %lu.\n\n", (n & bit_m));
}

/**
 * debug_3 - print debug statements
 *
 * @bit_m: bit_m of value n
 *
 * Return: nothing
*/
void debug_3(unsigned long int bit_m)
{
	printf("\nValue of bit_m is %lu after right shifting by one.\n\n", bit_m);
}

/**
 * _length - find the length of @n
 *
 * @n: value to find its length
 *
 * Return: length
*/
int _length(unsigned long int n)
{
	int length = 0;

	while (n > 0)
	{
		#ifdef DEBUG
		printf("Value of n is %lu before right shifting by one.\n\n", n);
		#endif

		length++;
		n >>= 1; /*shift n to the right by 1*/

		#ifdef DEBUG
		printf("Value of n is %lu after right shifting by one.\n\n", n);
		#endif
	}

	length--;

	return (length);
}

/**
 * print_binary - a function that converts a decimal to binary
 *
 * @n: decimal number to convert
 *
 * Return: nothing
*/
void print_binary(unsigned long int n)
{
	int length;
	unsigned long int bit_m = 1;

	length = _length(n);

	if (length > 0) /*create bit_m based on length of number*/
		bit_m <<= length; /*shift bit_m to the left by length*/
	#ifdef DEBUG
	debug_1(n, length, bit_m);
	#endif

	while (bit_m > 0)
	{
		#ifdef DEBUG
		debug_2(n, bit_m);
		#endif

		if (n & bit_m) /*if n & bit_m == 1 print 1*/
			_putchar('1');
		else /*else if n & bit_m == 0 print 0*/
			_putchar('0');

		bit_m >>= 1; /*shift bit_m to the right by 1*/

		#ifdef DEBUG
		debug_3(bit_m);
		#endif
	}
}

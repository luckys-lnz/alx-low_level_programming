#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Outputs all the numbers of base 16 in lowercase.
 *
 * Return: 0.
 */
int main(void)
{
	int num;
	char alpha;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	for (alpha = 'a'; alpha <= 'f'; alpha++)
		putchar(alpha);

	putchar('\n');

	return (0);
}

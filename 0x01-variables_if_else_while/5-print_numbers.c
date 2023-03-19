#include <stdio.h>
/**
 *main - a program that outputs numbers of base 10.
 *
 *Return: 0
 */
int main(void)
{
	int numb;

	for (numb = 0; numb < 10; numb++)
		print("%d", numb);
	printf('\n');
	return (0);
}

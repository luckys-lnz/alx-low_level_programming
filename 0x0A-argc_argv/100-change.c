#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - prints the minimum number of coins to make change for
 * an amount of money
 * @argc: represents number of arguments passed from prompt
 * @argv: an array of all arguments passed
 *
 * Description: Given cent coins of denominations 25, 10, 5, 2 and
 * 1; this program prints the number of these coins that will make
 * the passed in value (in cents)
 * Return: 0 if successful and 1 if error occurs
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int num;

	if (argc != 2)
	{
		printf("%s\n", "Error");
		return (1);
	}

	num = atoi(argv[1]);
	if (num < 0)
		printf("%d\n", 0);

	if (num / 25)
	{
		sum += num / 25;
		num %= 25;
	}

	if (num / 10)
	{
		sum += num / 10;
		num %= 10;
	}

	if (num / 5)
	{
		sum += num / 10;
		num %= 10;
	}

	if (num / 2)
	{
		sum += num / 2;
		num %= 2;
	}

	if (num / 1)
	{
		sum += num / 1;
		num %= 1;
	}
	printf("%d\n", sum);
	return (0);
}

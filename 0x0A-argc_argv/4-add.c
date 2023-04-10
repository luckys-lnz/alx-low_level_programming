#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - adds all positive numbers passed to program from prompt
 * @argc: represents number of arguments passed from prompt
 * @argv: an array of all arguments passed
 *
 * Return: 0 if successful and 1 if error occurs
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int num;

	while (--argc)
	{
		num = atoi(argv[argc]);
		if (!num)
		{
			printf("%s\n", "Error");
			return (1);
		}

		if (num < 0)
			continue;
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}

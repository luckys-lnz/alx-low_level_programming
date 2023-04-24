#include <stdlib.h>
#include <stdio.h>

/**
 *main - entry point
 *
 *Return: always 0
*/

int main(void)
{
	char *file_name;

	file_name = __FILE__;
	printf("%s\n", file_name);
	return (0);
}

#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int f_r, f_w, l, j, k;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	f_r = open(argv[1], O_RDONLY);
	if (f_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	f_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((l = read(f_r, buf, BUFSIZ)) > 0)
	{
		if (f_w < 0 || write(f_w, buf, l) != l)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(f_r);
			exit(99);
		}
	}
	if (l < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	j = close(f_r);
	k = close(f_w);
	if (j < 0 || k < 0)
	{
		if (j < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_r);
		if (k < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_w);
		exit(100);
	}
	return (0);
}

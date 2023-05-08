#include "main.h"

/**
 * read_textfile - a function that reads a text file and prints it
 *                to POSIX standard output.
 *
 * @filename: is the file to read
 * @letters: number of letters to read and print from file
 *
 * Return: 0 if it fails or actual number of letters it could
 *         read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f;
	ssize_t read_checker, wCount;
	char *b;

	if (filename == NULL) /*check if file is present*/
		return (0);

	f = open(filename, O_RDONLY); /*open file*/

	if (f == -1)
		return (0);

	/*get the size of buffer from number of letters*/
	b = malloc(sizeof(char) * letters);
	if (b == NULL)
	{
		free(b);
		return (0);
	}

	read_checker = read(f, b, letters); /*read file*/
	if (read_checker == -1) /*check if read failed*/
		return (0);

	wCount = write(STDOUT_FILENO, b, read_checker); /*write to POSIX*/
	if (wCount == -1 || read_checker != wCount) /*check if write failed*/
		return (0);

	free(b);

	close(f); /*close file*/

	return (wCount);
}
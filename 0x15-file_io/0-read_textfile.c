#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 *it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. 0 if the file
 * cannot be opened or read, if filename is NULL, or if write fails or does
 * not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

int fd, bytes_read, bytes_written;
char *buffer;
/* Check if filename is NULL */
if (filename == NULL)
return (0);
/* Allocate buffer */
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);
/* Open file for reading */
fd = open(filename, O_RDONLY);
if (fd == -1)
{
free(buffer);
return (0);
}
/* Read from file */
bytes_read = read(fd, buffer, letters);
if (bytes_read == -1)
{
free(buffer);
close(fd);
return (0);
}
/* Write to standard output */
bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
free(buffer);
close(fd);
return (0);
}
/* Cleanup and return the number of bytes written */
free(buffer);
close(fd);
return (bytes_written);
}

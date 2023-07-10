#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 *append_text_to_file - Appends text_content at the end of a file.
 *@filename: The name of the file.
 *@text_content: The text content to append.
 *
 *Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, length = 0;

	if (filename == NULL) /*Check if filename is NULL */
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND); /*Open the file in append mode */
	if (fd == -1) /*Check if file couldn't be opened */
		return (-1);

	if (text_content != NULL) /*Append text_content if it is not NULL */
	{
		while (text_content[length])
			length++;

		bytes_written = write(fd, text_content, length);
		/*Write text_content to the file */
		if (bytes_written == -1 || bytes_written != length)
		  /*Check for errors during write operation */
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

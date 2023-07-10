#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 *create_file - Creates a file with the given filename and writes the
 *              specified text_content to it.
 *@filename: The name of the file to create.
 *@text_content: The text content to write to the file.
 *
 *Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, length = 0;

	/*Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/*Open the file with the appropriate flags and permissions */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	/*Write text_content to the file if it is not NULL */
	if (text_content != NULL)
	{
		/*Calculate the length of the text_content string */
		while (text_content[length])
			length++;

		/*Write the text_content to the file */
		bytes_written = write(fd, text_content, length);
		if (bytes_written == -1 || bytes_written != length)
		{
			close(fd);
			return (-1);
		}
	}

	/*Close the file descriptor and return 1 on success */
	close(fd);
	return (1);
}

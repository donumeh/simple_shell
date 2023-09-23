#include "shell.h"

/**
 * _getline - reads a line of text
 * @lineptr: storage of read line
 * @n: the number of chars read
 * @fd: the descriptor
 *
 * Return: ssize_t
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[INITIAL_BUFFER_SIZE];
	static size_t buffer_position = 0, bytes_in_buffer = 0;
	ssize_t chars_read = 0, found_newline = 0, init_check = 0;
	size_t line_length = 0;

	init_check = init_line(lineptr, n);
	if (init_check == -1)
		return (init_check);
	while (1)
	{
		if (buffer_position >= bytes_in_buffer)
		{
			bytes_in_buffer = read(fd, buffer, INITIAL_BUFFER_SIZE);
			buffer_position = 0;
			if (bytes_in_buffer == 0)
			{
				if (line_length > 0)
				{
					(*lineptr)[line_length] = '\0';
					return (chars_read);
				}
			}
		}
		while (buffer_position < bytes_in_buffer)
		{
			if (buffer[buffer_position] == '\n')
			{
				found_newline = 1;
				break;
			}
			(*lineptr)[line_length++] = buffer[buffer_position++];
		}
		if (found_newline)
		{
			(*lineptr)[line_length] = '\0', buffer_position++;
			chars_read = line_length + 1;
			break;
		}
	}

	if ((size_t)chars_read > *n)
	{
		*n = chars_read, *lineptr = (char *)realloc(*lineptr, *n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (chars_read);
}

/**
 * init_line_ptr - checks the lineptr for error
 * @lineptr: the line ptr
 * @n: the number of chars
 *
 * Return: ssize_t
 */

ssize_t init_line(char **lineptr, size_t *n)
{
	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = malloc(sizeof(char) * *n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}

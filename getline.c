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
	static size_t buffer_position, bytes_in_buffer;
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
		if (newline_check(&found_newline, lineptr, &line_length,
					&buffer_position, &chars_read) == 0)
			break;
	}

	if (chars_check(&chars_read, n, lineptr) == NULL)
		return (-1);
	return (chars_read);
}

/**
 * init_line - checks the lineptr for error
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


/**
 * chars_check - checks the char
 * @chars_read: the number of chars read
 * @n: the number of value to read
 * @lineptr: the buffer to allocate
 *
 * Return: void *
 */

char *chars_check(ssize_t *chars_read, size_t *n, char **lineptr)
{
	if ((size_t)*chars_read > *n)
	{
		*n = *chars_read;
		*lineptr = (char *)realloc(*lineptr, *n);
		if (*lineptr == NULL)
		{
			return (NULL);
		}
	}
	return ("nill");
}

/**
 * newline_check - checks for new line
 * @found_newline: to find a newline
 * @lineptr: allocate mem
 * @line_length: length alloced
 * @buffer_position: position of buffer
 * @chars_read: number of chsrs read
 *
 * Return: 0 or -1 if otherwise
 */

int newline_check(ssize_t *found_newline, char **lineptr,
		size_t *line_length, size_t *buffer_position,
		ssize_t *chars_read)
{
	if (*found_newline)
	{
		(*lineptr)[*line_length] = '\0';
		*buffer_position += 1;
		*chars_read = *line_length + 1;
		return (0);
	}
	return (-1);
}

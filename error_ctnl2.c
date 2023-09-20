#include "shell.h"

/**
 * _perror - prints to stderr
 * @c: the char
 *
 * Return: values printed
 */

int _perror(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * print_interr - prints an integer
 * @n: the int value
 *
 * Return: void
 */

int print_interr(int n)
{
	if (n < 0)
	{
		_perror('-');
		n = (n * -1);
	}

	while (n / 10)
	{
		print_interr(n / 10);
	}
	return (1 + _perror((n % 10) + '0'));
}

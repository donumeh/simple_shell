#include "shell.h"

/**
 * print_error - detects and prints type of error
 * @error: Error
 *
 * Return: void.
 */

void print_error(int error)
{
	switch (error)
	{
		case EINVAL:
			write(STDERR_FILENO,
					"Bad arguments\n", 14);
			break;
		case ENOMEM:
			write(STDERR_FILENO,
					"Memory Issue\n", 13);
			break;
		case EAGAIN:
			write(STDERR_FILENO,
					"System imposed limit on number of threads\n", 42);
			break;
		default:
			write(STDERR_FILENO,
					"Error encountered\n", 18);
			break;
	}
}

/**
 * print_function_error - function had a problem
 *
 * Return: void
 */

void print_function_error(void)
{
	write(STDERR_FILENO,
			"Couldn't parse the required datatype\n", 37);
}

/**
 * print_exec_err - prints when execve encounters error
 * @av: shell interpreter
 * @cnt: num of cmd so far
 * @s: command not found
 *
 * Return: void
 */

void print_exec_err(char **av, int cnt, char *s)
{
	if (!s)
		return;
	dprintf(STDERR_FILENO,
			"%s: %d: %s: not found\n",
			av[0], cnt, s);
}

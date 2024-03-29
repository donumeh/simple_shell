#include "shell.h"

/**
 * builtin_exit - exit command
 * @line: the alloc line
 * @av: allloced av
 * @cnt: num of args passd so far
 * @aargs: args passed to program
 *
 * Return: void
 */

void builtin_exit(char *line, char **av, int cnt, char **aargs)
{
	int error = 0, at = 0;

	if (cnt == 1)
		cnt -= 1;
	if (av[1] != NULL)
		at = _atoi(av[1]);
	error = (av[1] == NULL) ? (cnt) :
		((at > 232) ? (232) : (at));

	if (av[1] != NULL)
	{
		if (_atoi(av[1]) == 2)
		{
			if (cnt == 0)
				cnt++;
			write(STDERR_FILENO, aargs[0], _strlen(aargs[0]));
			write(STDERR_FILENO, ": ", _strlen(": "));
			dprintf(STDERR_FILENO, "%d", cnt);
			write(STDERR_FILENO, ": ", _strlen(": "));
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, av[1], _strlen(av[1]));
			write(STDERR_FILENO, "\n", 1);
		}
		free_ptr(line);
		free_ptr_db(av);
		_exit(error);
	}
	else
	{
		free_ptr(line);
		free_ptr_db(av);
		_exit(error);
	}
}

/**
 * builtin_env - print the env variables
 * @line: stdin string
 * @argv: arg vector
 * @cnt: number of args passed so far
 * @av: args passed to program
 *
 * Return: void
 */

void builtin_env(UNUSED char *line, UNUSED char **argv,
		UNUSED int cnt, UNUSED char **av)
{
	int i, j;

	i = 0;
	while (environ[i])
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);
		_putchar('\n');
		i++;
	}
}

/**
 * _setenv - set environment
 * @name: name of the environment (key)
 * @value: the value of environ
 * @overwrite: what to append or write to it
 *
 * Return: int
 */

int _setenv(char *name, char *value, int overwrite)
{
	size_t name_len, value_len;
	char *env_entry = NULL;

	if (name == NULL || value == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	name_len = _strlen(name);
	value_len = _strlen(value);

	env_entry = malloc(name_len + value_len + 2);
	if (env_entry == NULL)
	{
		errno = ENOMEM;
		return (-1);
	}

	_strcpy(env_entry, name), _strcat(env_entry, "=");
	_strcat(env_entry, value);

	if (overwrite || _getenv(name) == NULL)
	{
		if (putenv(env_entry) == 0)
		{
			return (0);
		}
		else
		{
			free_ptr(env_entry);
			return (-1);
		}
	}
	else
	{
		free_ptr(env_entry);
		return (0);
	}
	free_ptr(env_entry);
}

/**
 * setenv_builtin - sets an env
 * @line: accepts string
 * @args: arg vecto
 * @cnt: num of args passed
 * @av: args passed to program
 *
 *
 * Return: void
 */

void setenv_builtin(UNUSED char *line, char **args,
		int cnt, char **av)
{
	int overwrite = 0;

	if (args[1] && args[2])
	{
		overwrite = 1;
		_setenv(args[1], args[2], overwrite);
	}
	else
	{
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", _strlen(": "));
		dprintf(STDERR_FILENO, "%d", cnt);
		write(STDERR_FILENO, ": ", _strlen(": "));
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}

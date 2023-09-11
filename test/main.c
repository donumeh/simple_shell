#include "shell.h"

/**
 * main - a shell replica
 * @ac: number of args passed
 * @av: the args passed
 * Return: 0.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	int cmd_cnt = 0;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", sizeof("($) "));
		get_keywords(av, &cmd_cnt);
	}
	return (0);
}

/**
 * get_keywords - gets the keywords from terminal using getline
 * @av: the args passed in CLI
 * @cnt: number of cmd typed
 *
 * Return: void
 */

void get_keywords(char **av, int *cnt)
{
	char *line = NULL, **argv = NULL;
	size_t n = 0;
	ssize_t glread = 0;
	int argc = 0, status = 0;
	pid_t child_process;

	/* getline and check for error */
	glread = getline(&line, &n, stdin);
	if (glread == -1)
	{
		print_error(errno);
		return;
	}
	/* tokenize the keywords */
	argv = tokenize_keywords(line, &argc);
	if (argv == NULL)
	{
		print_function_error();
		free_ptr(line);
		return;
	}
	free_ptr(line), *cnt += 1;
	/* run a child process to execve command */
	child_process = fork();
	if (child_process == -1)
	{
		print_error(errno);
		return;
	}

	if (child_process == 0) /* run command in child using execve */
	{
		execve(argv[0], argv, NULL);
		print_exec_err(av, *cnt, argv[0]);
		_exit(98);
	}
	else
	{
		wait(&status);
	}
	free_ptr_db(argv, argc);
}

/**
 * tokenize_keywords - tokenize the keywords passed into the tty
 * @line: the text/keys to tokenize
 * @argc: number of tokens
 *
 * Return: arrays of pointers to tokens
 */

char **tokenize_keywords(char *line, int *argc)
{
	char **argv = NULL, *token = NULL, *delim = " \n", *line_cpy = NULL;
	int i;

	if (line == NULL)
		return (NULL);
	/* duplicate string and increment argc for memalloc */
	line_cpy = strdup(line);
	if (line_cpy == NULL)
	{
		print_error(errno);
		return (NULL);
	}
	token = strtok(line_cpy, delim);
	while (token)
	{
		*argc += 1;
		token = strtok(NULL, delim);
	}
	free_ptr(line_cpy);
	argv = malloc(sizeof(char *) * (*argc));
	if (argv == NULL)
	{
		print_error(errno);
		return (NULL);
	}
	/* store token into argc (double ptr) */
	i = 0;
	token = strtok(line, delim);
	while (token)
	{
		argv[i] = strdup(token);
		if (argv[i++] == NULL)
		{
			free_ptr_db(argv, i - 1);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}

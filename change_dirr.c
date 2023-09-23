#include "shell.h"

/**
 * cd_builtin - change directory
 * @line: stored string
 * @args: arrays of command
 * @cnt: number of args passed so far
 * @av: the number of args passed to program
 */

void cd_builtin(UNUSED char *line, char **args,
		UNUSED int cnt, UNUSED char **av)
{
	char new_dir[MAX_DIR_LEN];
	char *home_dir = _getenv("HOME");
	char *old_dir = _getenv("OLDPWD");

	if (!args[1] || _strcmp(args[1], "~") == 0 ||
			_strcmp(args[1], "$HOME") == 0)
	{
		if (home_dir)
		{
			_strcpy(new_dir, "/");
			_strcat(new_dir, home_dir);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (old_dir)
		{
			_strcpy(new_dir, "/");
			_strcat(new_dir, old_dir);
		}
		printf("%s\n", new_dir);
	}
	else
	{
		_strcpy(new_dir, args[1]);
		printf("%s\n", new_dir);
	}

	if (chdir(new_dir) == 0)
	{
		char cwd[MAX_DIR_LEN];

		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			_setenv("PWD", cwd, 1);
		}
	}
	else
	{
		perror("cd");
	}
}

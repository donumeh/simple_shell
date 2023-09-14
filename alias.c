#include "shell.h"

/**
 * cleanup_aliases - cleans aliases
 *
 * Return: void
 */
void cleanup_aliases(void)
{
	int i;
    for (i = 0; i < alias_count; i++)
    {
	    free(aliases[i].name);
	    free(aliases[i].value);
    }
}

/**
 * alias_builtin - creates an alias built in
 * @line: the commands passed
 * @args: arrays of commands
 * @cnt: number of commands typed so far
 * @av: args passed to program in CLI
 *
 * Return: void
 */
void alias_builtin(UNUSED char *line, char** args,
		UNUSED int cnt, UNUSED char **av)
{
	if (args[1] == NULL)
	{
		int i;
		
		for (i = 0; i < alias_count; i++)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		}
	}
	else if (args[1] && args[2] == NULL)
	{
		int i;
		
		for (i = 0; i < alias_count; i++)
		{
			if (strcmp(aliases[i].name, args[1]) == 0)
			{
				printf("%s='%s'\n", aliases[i].name, aliases[i].value);
				return;
			}
		}
	}
	else if (args[1] && args[2])
	{
		int i;

		for (i = 1; args[i] != NULL; i++)
		{
			char* name = args[i];
			char* equals_pos = strchr(name, '=');
			
			if (equals_pos != NULL)
			{
				char *value;
				int found, j;
				
				*equals_pos = '\0';
				value = equals_pos + 1;
				found = 0;
				
				for (j = 0; j < alias_count; j++)
				{
					if (strcmp(aliases[j].name, name) == 0)
					{
						found = 1;
						free(aliases[j].value);
						aliases[j].value = strdup(value);
						break;
					}
				}
				
				if (!found && alias_count < MAX_ALIASES)
				{
					aliases[alias_count].name = strdup(name);
					aliases[alias_count].value = strdup(value);
					alias_count++;
				}
			}
		}
	}
	else
	{
		printf("I'm here\n");
	}
}

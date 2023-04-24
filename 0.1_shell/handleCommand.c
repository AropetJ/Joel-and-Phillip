#include <stdio.h>
#include "main.h"

/**
 * handleCommand - handles entered command
 * @cmd: entered command
 *
 * Return: 0 if success else -1
 */

int handleCommand(char *cmd)
{
	int status;
	size_t i, j, word_count;
	char **args, **prog_args;
	char *process_path;

	args = _strtok(cmd, &word_count);
	prog_args = malloc(sizeof(char *) * (word_count - 1));

	for (i = 0; i < word_count; i++)
	{
		if (i == 0)
			process_path = *(args + i);
		else
		{
			*prog_args = *(args + i);
			prog_args++;
		}
	}
	status = runprog(process_path, prog_args);

	for (j = 0; j < word_count; j++)
	{
		free(*(args + j));
	}
	free(args);

	if (status == 0)
		return (-1);

	return (0);
}

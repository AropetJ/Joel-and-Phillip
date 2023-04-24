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
	char **args;

	args = _strtok(cmd, &word_count);
	status = runprog(args[0], args);

	for (j = 0; j < word_count; j++)
	{
		free(*(args + j));
	}
	free(args);

	if (status == 0)
		return (-1);

	return (0);
}

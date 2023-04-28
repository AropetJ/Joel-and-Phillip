#include "shell.h"

/**
 * handleCommand - handles entered command
 * @cmd: entered command
 *
 * Return: void
 */

void handleCommand(char *cmd)
{
	size_t j, word_count;
	char **args;

	args = _strtok(cmd, &word_count);
	runprog(args[0], args);
	for (j = 0; j < word_count; j++)
	{
		free(*(args + j));
	}
	free(args);
}

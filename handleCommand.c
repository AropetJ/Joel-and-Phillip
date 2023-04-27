#include "main.h"

/**
 * handleCommand - handles entered command
 * @cmd: entered command
 * @prompter: prompt name
 *
 * Return: void
 */

void handleCommand(char *cmd, char *prompter)
{
	size_t j, word_count;
	char **args;

	args = _strtok(cmd, &word_count);
	runprog(args[0], args, prompter);
	for (j = 0; j < word_count; j++)
	{
		free(*(args + j));
	}
	free(args);
}

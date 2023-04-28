<<<<<<< HEAD
#include "shell.h"
=======
#include "main.h"
>>>>>>> c54db66c8ac4a74de9bf819d98348ae36b6f24cb

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

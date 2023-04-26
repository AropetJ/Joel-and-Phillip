#include "shell.h"

/**
 * handleCommand - handles entered command
 * @cmd: entered command
 *
 * Return: 0 if success else -1
 */

int handleCommand(char *cmd)
{
	int status;

	status = runprog(cmd);

	if (status == 0)
		return (-1);

	return (0);
}

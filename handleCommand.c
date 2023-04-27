#include <stdio.h>
#include "main.h"

/**
 * handleCommand - handles entered command
 * @cmd: entered command
 *
 * Return: void
 */

void handleCommand(char *cmd)
{
	int status;

	status = runprog(cmd);

	if (status == 0)
		return (-1);

	return (0);
}

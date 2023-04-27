#include <stdio.h>
#include "main.h"

/**
 * main- offers input prompt
 * @ac: argument count
 * @av: argument vector
 *
 * Return: void
 */

int main(__attribute((unused)) int ac, char **av)
{
	char *command;
	size_t size;
	int read;
	int exec_status;
	
	size = 0;

	while (1)
	{
		printf("#cisfun$ ");
		if ((read = getline(&command, &size, stdin)) == -1)
			break;
		
		command[read-1] = '\0';
		exec_status = handleCommand(command);
		if (exec_status == -1)
			printf("%s: No such file or directory\n", av[0]);
	}

	return (0);
}

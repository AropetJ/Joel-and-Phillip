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
	char *buf;
	int read;
	size_t size;

	size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read = getline(&buf, &size, stdin);
		if (read == -1)
		{
			free(buf);
			exit(EXIT_FAILURE);
		}

		buf[read - 1] = '\0';
		handleCommand(buf, av[0]);
	}
	return (0);
}

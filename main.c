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
	int read, status;
	size_t size;
	pid_t child_pid;
	char *args[] = {NULL, NULL};

	size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		read = getline(&buf, &size, stdin);
		if (read == -1)
		{
			free(buf);
			exit(EXIT_FAILURE);
		}
		buf[read - 1] = '\0';

		args[0] = buf;
		child_pid = fork();
		if (child_pid < 0)
		{
			free(buf);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				printf("%s: No such file or directory\n", av[0]);
			}
		}
		else
		{
			wait(&status);
		}

	}
	return (0);
}

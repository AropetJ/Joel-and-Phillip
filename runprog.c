#include "shell.h"

/**
 * runprog - execute a program
 * @path: process path
 * @args: command args
 *
 * Return: void
 */

void runprog(char *path, char **args)
{
	int status;
	int pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, NULL) == -1)
			write(1, "./shell: No such file or directory\n", 35);
	}

	if (pid < 0)
	{
		perror("ERROR:Parent completed execution before the child     process");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

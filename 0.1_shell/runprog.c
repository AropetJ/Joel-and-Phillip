#include <stdio.h>
#include <sys/stat.h>
#include "main.h"

/**
 * runprog - execute a program
 * @path: process path
 * @arg: program arguments
 *
 * Return: 1 if success else 0
 */

int runprog(char *path, char **arg)
{
	pid_t child_pid;
	int status;
	char *envp[] = {NULL};
	char *temp_path;

	char *val;

	struct stat bf;

	if (stat(path, &bf) != 0)
	{
		return (0);
	}

	child_pid = fork();
	if (child_pid < 0)
		return (0);

	if (child_pid == 0)
	{
		execve(path, arg, envp);
	}
	else
		wait(&status);

	return (1);
}

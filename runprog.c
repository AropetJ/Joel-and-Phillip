#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * runprog - execute a program
 * @path: process path
 *
 * Return: 1 if success else 0
 */

int runprog(char *path)
{
	pid_t child_pid;
	int status;
	char *args[] = {NULL};

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
		execve(path, args, args);
	}
	else
		wait(&status);

	return (1);
}

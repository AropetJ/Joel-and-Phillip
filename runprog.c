#include "main.h"

/**
 * runprog - execute a program
 * @path: process path
 * @args: command args
 * @prompter: prompt name
 *
 * Return: void
 */

void runprog(char *path, char **args, char *prompter)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
		exit(EXIT_FAILURE);

	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
			printf("%s: No such file or directory\n", prompter);
	}
	else
		wait(&status);
}

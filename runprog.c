#include "shell.h"

/**
 * runprog - execute a program
 * @path: process path
 * @args: command args
 * @prompter: prompt name
 *
 * Return: void
 */

void runprog(char *path, char **args)
{
	if (execve(path, args, NULL) == -1)
		write(1,"./shell: No such file or directory\n", 35);
}

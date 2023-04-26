#include "shell.h"

/**
 * main - entry point
 *
 * Return: Always zero
 *
 */

int main(__attribute((unused))int argc, char **argv)
{
	char *buff;
	size_t n;
	int exit_status;
	ssize_t wp;

	n = 0;

	while (1)
	{
		printf("#cisfun$ ");
		wp = getline(&buff, &n, stdin);

		if (wp != EOF || wp == '\n')
		{
			buff = '\0';
			exit_status = handleCommand(buff);
			if (exit_status == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
			}
			free(buff);
		}
	}

	return (0);
}

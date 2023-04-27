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
	int exec_status, read;
	size_t size;

	size = 0;
	printf("$: ");
	while ((read = getline(&buf, &size, stdin)) != -1)
	{
		buf[read - 1] = '\0';
		exec_status = handleCommand(buf);
		if (exec_status == -1)
		{
			printf("%s: No such file or directory\n", av[0]);
		}
		free(buf);
		printf("$: ");
	}
	return (0);
}

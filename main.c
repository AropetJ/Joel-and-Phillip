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
	char c;
	char *buf;
	char *wp;
	int exec_status;

	buf = malloc(sizeof(char) * 100);
	wp = buf;

	printf("$: ");
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			wp = '\0';
			exec_status = handleCommand(buf);
			if (exec_status == -1)
			{
				printf("%s: No such file or directory\n", av[0]);
			}

			free(buf);
			buf = malloc(sizeof(char) * 100);
			wp = buf;
			printf("$: ");
		}
		else
		{
			*wp = c;
			wp++;
		}
	}
	return (0);
}

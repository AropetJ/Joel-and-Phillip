#include <stdio.h>
#include "main.h"

/**
 * main- offers input prompt
 *
 * Return: void
 */

void main(void)
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
				printf("%s: No such file or directory\n", buf);
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
}

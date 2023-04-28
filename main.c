#include "shell.h"

/**
 * main- offers input prompt
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: void
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *buf = NULL;
	char *sh = "#cisfun$ ";
	ssize_t prompt;
	size_t n = 0;
	int term;

	while (1)
	{
		term = isatty(STDIN_FILENO);
		if (term)
			write(1, sh, 9);
		prompt = getline(&buf, &n, stdin);
		if (prompt == -1)
		{
			if (term && feof(stdin))
				term = 0;
			break;
		}

		if ((buf[prompt - 1] == '\n'))
			(buf[prompt - 1]) = '\0';

		if (_strcmp(buf, "exit") == 0)
			break;

		handleCommand(buf);
	}
	free(buf);
	return (0);
}

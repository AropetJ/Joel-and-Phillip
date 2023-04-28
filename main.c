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
	/* char *args; */
	bool piped = false;
	int term;

	while (1 && !piped)
	{
		term = isatty(STDIN_FILENO);
		if (term == 0)
		{
			piped = true;
		}

		write(1, sh, 9);
		prompt = getline(&buf, &n, stdin);
		if (prompt == -1)
		{
			perror("ERROR: Getline failed");
			free(buf);
			exit(EXIT_FAILURE);
		}
		if ((buf[prompt - 1] == '\n'))
			(buf[prompt - 1]) = '\0';

		handleCommand(buf);
	}
	free(buf);
	return (0);
}

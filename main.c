#include "shell.h"

/**
 * main- offers input prompt
 * @ac: argument count
 * @av: argument vector
 *
 * Return: void
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv, __attribute__((unused))char **env)
{
	char *buf = NULL;
	char *sh = "#cisfun$ ";
	ssize_t prompt;
	size_t n = 0;
	/* char *args; */
	bool piped = false;
	int term;
	int pid;
	/* struct stat st;*/
	int status;

	/* enter into the loop that will continously print the prompt */
	while (1 && !piped)
		{
			/* check whether input is coming from a pipe */
			term = isatty(STDIN_FILENO);
			if (term == 0)
			{
				piped = true;
			}

			/* print the first prompt to the terminal */
			write(1, sh, 9);
	
			/* read input from the user */
			prompt = getline(&buf, &n, stdin);

			/* if getline fails, print an error message and free buf */
			if (prompt == -1)
			{
				perror("ERROR: Getline failed"); 
				free(buf);
				exit(EXIT_FAILURE);
			}
			/* if the buffer ends with a newline character, replace it with a null terminated character */
			if ((buf[prompt - 1] = '\n'))
				(buf[prompt - 1]) = '\0';

			/* create a child process that we shall use for execution of our program */
			pid = fork();
			
			/* execute the program */
			if (pid == 0)
			{
				handleCommand(buf);
			}
			else
				wait(&status);
			
			/* Make sure the parent process waits for the child */
			if (pid < 0)
			{
				perror("ERROR:Parent completed execution before the child process");
				exit(EXIT_FAILURE);
			}
		}
		free(buf);
		return 0;
}

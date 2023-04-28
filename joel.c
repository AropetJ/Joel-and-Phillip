#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *buf = NULL;
	char *sh = "#cisfun$ ";
	ssize_t prompt;
	size_t n = 0;
	bool piped = true;
	int term;
	int pid;
	struct stat st;
	int wstatus;

	/* enter into the loop that will continously print the prompt */
	while (1 && piped)
		{
			/* check whether input is coming from a pipe */
			term = isatty(STDIN_FILENO);
			if (term == 1)
			{
				piped = true;
			}
			else if (term == 0)
			{
				piped = false;
				perror("ERROR: No input from stdin");
				exit(EXIT_FAILURE);
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
			if (buf[prompt - 1] = '\n')
				buf[prompt - 1] = '\0';

			/* create a child process that we shall use for execution of our program */
			pid = fork();
			
			/* Handle the error case */
			if (pid == -1)
			{
				perror("ERROR: Failed to fork parent process");
				exit(EXIT_FAILURE);
			}
			/* execute the program */
			else if (pid == 0)
			{
				runprog(buf, &st, env);
			}
			
			/* Make sure the parent process waits for the child */
			if (waitpid(pid, &wstatus, 0) == -1)
			{
				perror("ERROR:Parent completed execution before the child process");
				exit(EXIT_FAILURE);
			}
		}
		free(buf);
		return 0;
}

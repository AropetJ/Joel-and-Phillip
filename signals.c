#include "shell.h"

/**
 * handle_signal - handle the ctrl+C signal.
 *
 * Return: Void.
 */

typedef void (*sighandler)(int);
char c = '\0';

void handle_signal(__attribute__((unused))int sign)
{
	printf("\n#cisfun$ ");
	fflush(stdout);
}

#include "main.h"

/**
 * main - Entry point.
 *
 * Return: 0 always.
 */

int main(void)
{
	char *c = "Hello world\n";

	while (*c)
		putchar(*c++);

	return (0);
}

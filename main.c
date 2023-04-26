#include "main.h"

/**
 * main - Entry point.
 *
 * Return: 0 always.
 */

int main(void)
{
	char *c = "Hello world";

	while (*c)
	{
		putchar(*c++);
	}
	putchar('\n');
	return (0);
}

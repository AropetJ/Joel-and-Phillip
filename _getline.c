#include "main.h"
/**
 * _getline - implementation on getline
 * @buf: char pointer
 * @size: pointer to data size
 * @stream: file descriptor to read from
 *
 * Return:  -1 if EOF
 */

int _getline(char *buf, size_t *size, FILE *stream)
{
	int status;
	char c;
	
	status = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			status = -1;
		}
		else if (c == '\n')
		{
			*buf = c;
			buf++;
			break;	
		}
		*buf = c;
		buf++;
	}
	return status;
}

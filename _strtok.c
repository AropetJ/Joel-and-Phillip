#include "main.h"

/**
 * _strtok - splits string into words
 * @command: pointer to string
 * @count: pointer to word count
 *
 * Return: double pointer to words
 */


char **_strtok(char *command, size_t *count)
{
	static size_t MAXWORDS = 100;
	static size_t MAXWORDLENGTH = 50;
	char **words;
	char *word;
	size_t i, j, word_count;
	char c;

	if (!command)
		return (NULL);
	word_count = 0;
	words = malloc(sizeof(char *) * MAXWORDS);

	word = malloc(sizeof(char) * MAXWORDLENGTH);
	for (i = 0, j = 0; (c = *(command + i)); i++)
	{
		if (c != ' ' || c != '\n' || c != '\0')
			*(word + j) = c;
		else
		{
			*(word + j) = '\0';
			*(words + word_count) = word;
			word = malloc(sizeof(char) * MAXWORDLENGTH);
			j = 0;
			word_count++;
			continue;
		}
		j++;
	}

	*(word + j) = '\0';
	*(words + word_count) = word;
	word = malloc(sizeof(char) * MAXWORDLENGTH);
	word_count++;
	*count = word_count;
	return (words);
}

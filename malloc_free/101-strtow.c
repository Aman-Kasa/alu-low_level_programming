#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	int i, j, k, word_count = 0, len = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	/* Count words */
	for (i = 0; str[i]; i++)
		if ((i == 0 && str[i] != ' ') ||
		    (str[i] != ' ' && str[i - 1] == ' '))
			word_count++;

	if (word_count == 0)
		return (NULL);

	/* Allocate array of pointers */
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			len = 0;
			while (str[i + len] != ' ' && str[i + len])
				len++;

			words[k] = malloc(sizeof(char) * (len + 1));
			if (words[k] == NULL)
			{
				while (k--)
					free(words[k]);
				free(words);
				return (NULL);
			}

			for (j = 0; j < len; j++)
				words[k][j] = str[i + j];
			words[k][j] = '\0';
			k++;
			i += len;
		}
		else
			i++;
	}
	words[k] = NULL;

	return (words);
}


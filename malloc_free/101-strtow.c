#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * count_words - counts the number of words in a string
 * @s: input string
 *
 * Return: number of words
 */
int count_words(char *s)
{
	int i = 0, words = 0;

	if (!s)
		return (0);

	while (s[i])
	{
		while (s[i] && isspace(s[i]))
			i++;
		if (s[i] && !isspace(s[i]))
			words++;
		while (s[i] && !isspace(s[i]))
			i++;
	}
	return (words);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to array of strings, or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j = 0, w = 0, start, end, word_count;

	if (!str || !*str)
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);

	while (str[i] && w < word_count)
	{
		while (str[i] && isspace(str[i]))
			i++;
		start = i;
		while (str[i] && !isspace(str[i]))
			i++;
		end = i;

		words[w] = malloc(sizeof(char) * (end - start + 1));
		if (!words[w])
		{
			while (w-- > 0)
				free(words[w]);
			free(words);
			return (NULL);
		}

		for (j = 0; start < end; j++, start++)
			words[w][j] = str[start];
		words[w][j] = '\0';
		w++;
	}
	words[w] = NULL;
	return (words);
}


#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: input string
 * Return: number of words
 */
int count_words(char *str)
{
	int i = 0, count = 0;

	if (!str)
		return (0);

	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

/**
 * word_len - returns the length of a word starting at str
 * @str: pointer to start of word
 * Return: length of word
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

/**
 * copy_word - copies a single word from src to dest
 * @src: source string
 * @dest: destination string
 * @len: length of word
 */
void copy_word(char *src, char *dest, int len)
{
	int i;

	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * allocate_words - allocates memory for all words
 * @word_count: number of words
 * Return: pointer to array of strings, or NULL
 */
char **allocate_words(int word_count)
{
	char **words;
	int i;

	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);

	for (i = 0; i < word_count; i++)
		words[i] = NULL;
	words[word_count] = NULL;

	return (words);
}

/**
 * strtow - splits a string into words
 * @str: input string
 * Return: pointer to array of words, or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, k = 0, wcount, wlen;

	if (!str || *str == '\0')
		return (NULL);

	wcount = count_words(str);
	if (wcount == 0)
		return (NULL);

	words = allocate_words(wcount);
	if (!words)
		return (NULL);

	while (str[i] && k < wcount)
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			break;

		wlen = word_len(str + i);
		words[k] = malloc(wlen + 1);
		if (!words[k])
		{
			while (k > 0)
			{
				k--;
				free(words[k]);
			}
			free(words);
			return (NULL);
		}

		copy_word(str + i, words[k], wlen);
		i += wlen;
		k++;
	}
	words[k] = NULL;
	return (words);
}


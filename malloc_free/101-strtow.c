#include "main.h"
#include <stdlib.h>

/**
 * word_count - counts the number of words in a string
 * @s: input string
 *
 * Return: number of words
 */
int word_count(char *s)
{
    int i, count = 0;

    if (!s)
        return (0);

    for (i = 0; s[i]; i++)
    {
        if ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n') &&
            (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n'))
            count++;
    }

    return (count);
}

/**
 * word_length - returns the length of a word starting at s
 * @s: input string
 *
 * Return: length of word
 */
int word_length(char *s)
{
    int len = 0;

    while (s[len] && s[len] != ' ' && s[len] != '\t' && s[len] != '\n')
        len++;

    return (len);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to array of words, or NULL on failure
 */
char **strtow(char *str)
{
    char **words;
    int i = 0, j, k, wc, wl;

    if (!str || str[0] == '\0')
        return (NULL);

    wc = word_count(str);
    if (wc == 0)
        return (NULL);

    words = malloc(sizeof(char *) * (wc + 1));
    if (!words)
        return (NULL);

    for (j = 0; j < wc; j++)
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;

        wl = word_length(str + i);
        words[j] = malloc(sizeof(char) * (wl + 1));
        if (!words[j])
        {
            for (k = 0; k < j; k++)
                free(words[k]);
            free(words);
            return (NULL);
        }

        for (k = 0; k < wl; k++)
            words[j][k] = str[i++];

        words[j][k] = '\0';
    }

    words[wc] = NULL;

    return (words);
}


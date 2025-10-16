#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts words in a string
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
 * word_len - counts length of a word starting at str
 * @str: string starting at word
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
 * strtow - splits a string into words
 * @str: input string
 * Return: pointer to array of strings, or NULL
 */
char **strtow(char *str)
{
    char **words;
    int i = 0, j = 0, k = 0, wcount, wlen;

    if (!str || *str == '\0')
        return (NULL);

    wcount = count_words(str);
    if (wcount == 0)
        return (NULL);

    words = malloc((wcount + 1) * sizeof(char *));
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

        for (j = 0; j < wlen; j++)
            words[k][j] = str[i + j];
        words[k][j] = '\0';
        i += wlen;
        k++;
    }
    words[k] = NULL;
    return (words);
}


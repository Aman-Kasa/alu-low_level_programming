#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Helper: count number of words in a string */
int count_words(char *str)
{
    int count = 0, i = 0;

    if (!str)
        return 0;

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
    return count;
}

/* Helper: allocate memory for each word */
char **allocate_words(int words)
{
    char **array;
    int i;

    array = malloc((words + 1) * sizeof(char *));
    if (!array)
        return NULL;

    for (i = 0; i < words; i++)
        array[i] = NULL;
    array[words] = NULL;

    return array;
}

/* Helper: copy words into array */
void copy_words(char *str, char **array)
{
    int i = 0, j, k = 0, x, len;

    while (str[i])
    {
        while (str[i] && str[i] == ' ')
            i++;
        if (!str[i])
            break;
        j = i;
        while (str[i] && str[i] != ' ')
            i++;
        len = i - j;
        array[k] = malloc(len + 1);
        if (!array[k])
        {
            for (x = 0; x < k; x++)
                free(array[x]);
            free(array);
            return;
        }
        strncpy(array[k], str + j, len);
        array[k][len] = '\0';
        k++;
    }
}

/* Main function: split string into words */
char **strtow(char *str)
{
    int words;
    char **result;

    if (!str || *str == '\0')
        return NULL;

    words = count_words(str);
    if (words == 0)
        return NULL;

    result = allocate_words(words);
    if (!result)
        return NULL;

    copy_words(str, result);

    return result;
}


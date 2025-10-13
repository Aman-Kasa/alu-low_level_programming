#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all arguments of the program
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to new string, or NULL if failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, pos = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length of all strings + newlines */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* for '\n' */
	}

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	/* Copy arguments into new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[pos++] = av[i][j];
		str[pos++] = '\n';
	}
	str[pos] = '\0';

	return (str);
}


#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check argstostr
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	char *s;

	s = argstostr(ac, av);
	if (s == NULL)
		return (1);

	printf("%s", s);
	free(s);
	return (0);
}


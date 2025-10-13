#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_tab - prints array of strings
 * @tab: array to print
 */
void print_tab(char **tab)
{
	int i;

	for (i = 0; tab[i] != NULL; i++)
		printf("%s\n", tab[i]);
}

/**
 * main - check strtow
 *
 * Return: 1 if error, 0 otherwise
 */
int main(void)
{
	char **tab;

	tab = strtow("      Best School         #cisfun      ");
	if (tab == NULL)
	{
		printf("Failed\n");
		return (1);
	}

	print_tab(tab);
	return (0);
}


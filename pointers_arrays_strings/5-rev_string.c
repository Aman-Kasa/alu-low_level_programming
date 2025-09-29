#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int i = 0, j;
	char tmp;

	/* find the string length */
	while (s[i] != '\0')
		i++;

	/* reverse in-place */
	for (j = 0; j < i / 2; j++)
	{
		tmp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = tmp;
	}
}

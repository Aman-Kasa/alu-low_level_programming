#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times in lowercase
 */
void print_alphabet_x10(void)
{
	int i, j;

	for (i = 0; i < 10; i++)      /* repeat 10 times */
	{
		for (j = 'a'; j <= 'z'; j++)  /* print a to z */
			_putchar(j);
		_putchar('\n');           /* newline after each alphabet */
	}
}

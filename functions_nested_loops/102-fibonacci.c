#include "main.h"
#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a = 1, b = 2, next;
	int count;

	printf("%lu, %lu", a, b);
	for (count = 3; count <= 50; count++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}
	printf("\n");
	return (0);
}

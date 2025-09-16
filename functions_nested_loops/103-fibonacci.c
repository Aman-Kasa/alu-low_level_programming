#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued
 * Fibonacci terms not exceeding 4,000,000
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a = 1, b = 2, next, sum = 2;

	next = a + b;
	while (next <= 4000000)
	{
		if (next % 2 == 0)
			sum += next;
		a = b;
		b = next;
		next = a + b;
	}
	printf("%lu\n", sum);
	return (0);
}

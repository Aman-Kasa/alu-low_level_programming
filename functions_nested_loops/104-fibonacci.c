#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, next;
	unsigned long f1_h = 0, f2_h = 0, next_h;
	int i;

	printf("%lu, %lu", f1, f2);
	for (i = 3; i <= 98; i++)
	{
		/* Add low parts */
		next = f1 + f2;
		next_h = f1_h + f2_h;

		/* Handle overflow of unsigned long (simulate high part) */
		if (next < f1)
		{
			next_h += 1;
		}

		/* Print depending if high part is zero or not */
		if (next_h == 0)
			printf(", %lu", next);
		else
			printf(", %lu%09lu", next_h, next);

		/* Shift numbers */
		f1 = f2;
		f1_h = f2_h;
		f2 = next;
		f2_h = next_h;
	}
	printf("\n");
	return (0);
}

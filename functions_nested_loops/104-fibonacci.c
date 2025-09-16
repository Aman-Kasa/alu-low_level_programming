#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, separated by comma and space
 * Return: Always 0
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2;
	unsigned long f1_h = 0, f1_l = 1;
	unsigned long f2_h = 0, f2_l = 2;
	unsigned long next_h, next_l;
	int i;

	printf("%lu, %lu", f1, f2);

	for (i = 3; i <= 98; i++)
	{
		if (f2 < 1000000000UL)
		{
			unsigned long next = f1 + f2;
			printf(", %lu", next);
			f1 = f2;
			f2 = next;
		}
		else
		{
			next_l = f1_l + f2_l;
			next_h = f1_h + f2_h;
			if (next_l >= 1000000000UL)
			{
				next_l -= 1000000000UL;
				next_h += 1;
			}
			printf(", %lu%09lu", next_h, next_l);
			f1_l = f2_l;
			f1_h = f2_h;
			f2_l = next_l;
			f2_h = next_h;
		}
	}
	printf("\n");
	return (0);
}

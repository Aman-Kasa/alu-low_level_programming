#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, separated by comma and space
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long f1 = 0, f2 = 1, f3;
	unsigned long f1_h, f1_l, f2_h, f2_l;
	unsigned long h1, h2;
	int i;

	for (i = 1; i <= 92; i++) /* first 92 fit in unsigned long */
	{
		f3 = f1 + f2;
		printf("%lu", f3);
		if (i != 92)
			printf(", ");
		f1 = f2;
		f2 = f3;
	}

	f1_h = f1 / 10000000000UL;
	f1_l = f1 % 10000000000UL;
	f2_h = f2 / 10000000000UL;
	f2_l = f2 % 10000000000UL;

	for (; i <= 98; i++)
	{
		h1 = f1_h + f2_h;
		h2 = f1_l + f2_l;
		if (h2 >= 10000000000UL)
		{
			h1 += 1;
			h2 -= 10000000000UL;
		}
		printf(", %lu%010lu", h1, h2);

		f1_h = f2_h;
		f1_l = f2_l;
		f2_h = h1;
		f2_l = h2;
	}

	printf("\n");
	return (0);
}

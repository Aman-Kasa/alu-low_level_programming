#include "main.h"

/**
 * print_times_table - prints n times table starting from 0
 * @n: number of the times table
 */
void print_times_table(int n)
{
    int i, j, prod;

    if (n < 0 || n > 15)
        return;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            prod = i * j;
            if (j != 0)
                _putchar(',');
            _putchar(' ');
            if (prod < 10)
                _putchar(' ');
            if (prod < 100)
                _putchar(' ');
            if (prod >= 100)
                _putchar((prod / 100) + '0');
            if (prod >= 10)
                _putchar(((prod / 10) % 10) + '0');
            _putchar((prod % 10) + '0');
        }
        _putchar('\n');
    }
}

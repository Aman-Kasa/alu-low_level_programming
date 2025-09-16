#include <stdio.h>

/**
 * main - prints first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
    long a = 1, b = 2, c;
    int i;

    printf("%ld, %ld", a, b);

    for (i = 3; i <= 50; i++)
    {
        c = a + b;
        printf(", %ld", c);
        a = b;
        b = c;
    }

    printf("\n");
    return (0);
}

#include <stdio.h>

/**
 * main - prints sum of even Fibonacci numbers not exceeding 4,000,000
 *
 * Return: Always 0
 */
int main(void)
{
    long a = 1, b = 2, c, sum = 2;

    while (1)
    {
        c = a + b;
        if (c > 4000000)
            break;
        if (c % 2 == 0)
            sum += c;
        a = b;
        b = c;
    }

    printf("%ld\n", sum);
    return (0);
}

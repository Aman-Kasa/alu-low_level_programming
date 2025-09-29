#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: pointer to the string to convert
 *
 * Return: integer value or 0 if no digits found
 */
int _atoi(char *s)
{
    int i = 0, neg_count = 0, sign = 1, result = 0;

    while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
    {
        if (s[i] == '-')
            neg_count++;
        i++;
    }

    if (neg_count % 2 != 0)
        sign = -1;

    while (s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        if (result > (INT_MAX - digit) / 10)
            return (sign == 1 ? INT_MAX : INT_MIN);

        result = result * 10 + digit;
        i++;
    }

    return (result * sign);
}

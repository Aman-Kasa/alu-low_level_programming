#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The integer value represented in the string.
 */
int _atoi(char *s)
{
    int i = 0, sign = 1, num = 0;

    /* Skip non-digit characters, handle signs */
    while (s[i] != '\0')
    {
        if (s[i] == '-')
            sign *= -1;
        else if (s[i] == '+')
            ; /* do nothing, sign unchanged */
        else if (s[i] >= '0' && s[i] <= '9')
            break;
        i++;
    }

    /* Convert digits to integer */
    while (s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }

    return (num * sign);
}


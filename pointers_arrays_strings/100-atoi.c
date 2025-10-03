#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer representation of string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0, digit;

	/* Skip non-digit chars and handle + / - signs */
	while (s[i])
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
			break;
		i++;
	}

	/* Convert digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';

		/* Check overflow before multiplying or adding */
		if (sign == 1 && num > (INT_MAX - digit) / 10)
			return (INT_MAX);
		if (sign == -1 && num > (-(INT_MIN + digit)) / 10)
			return (INT_MIN);

		num = num * 10 + digit;
		i++;
	}

	return (num * sign);
}


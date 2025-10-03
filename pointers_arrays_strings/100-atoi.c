#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, 0 if no digits found
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, digits_found = 0;
	unsigned int result = 0;
	int digit;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			digits_found = 1;

			if (sign == 1 && result > (INT_MAX - digit) / 10)
				return (INT_MAX);
			if (sign == -1 && result > ((unsigned int)INT_MAX + 1 - digit) / 10)
				return (INT_MIN);

			result = result * 10 + digit;
		}
		else if (digits_found)
			break;

		i++;
	}

	if (!digits_found)
		return (0);

	if (sign == -1)
	{
		if (result == (unsigned int)INT_MAX + 1)
			return (INT_MIN);
		return (-(int)result);
	}
	return ((int)result);
}


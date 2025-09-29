#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: integer value or 0
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0;
	int found_digit = 0;

	/* Skip non-digit characters, handle signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			break;
		}
		i++;
	}

	if (!found_digit)
		return (0);

	/* Convert digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		int digit = s[i] - '0';

		/* Check overflow */
		if (result > (INT_MAX - digit) / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);

		result = result * 10 + digit;
		i++;
	}

	return (result * sign);
}

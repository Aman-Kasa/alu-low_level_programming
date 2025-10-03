#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: converted integer
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0;
	int digit;

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

	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';

		if (sign == 1 && num > (2147483647 - digit) / 10)
			return (2147483647);
		if (sign == -1 && num > (2147483648 - digit) / 10)
			return (-2147483648);

		num = num * 10 + digit;
		i++;
	}

	return (num * sign);
}


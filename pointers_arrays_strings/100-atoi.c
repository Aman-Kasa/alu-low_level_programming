#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string
 *
 * Return: Converted integer, or 0 if no numbers found.
 */
int _atoi(char *s)
{
	int i, sign, num, digits_found, digit_val;

	i = 0;
	sign = 1;
	num = 0;
	digits_found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit_val = s[i] - '0';
			digits_found = 1;

			/* Overflow check for positive numbers */
			if (sign == 1 && num > (2147483647 - digit_val) / 10)
				return (2147483647);

			/* Overflow check for negative numbers */
			if (sign == -1 && num > (2147483648 - digit_val) / 10)
				return (-2147483648);

			num = num * 10 + digit_val;
		}
		else if (digits_found)
			break;

		i++;
	}

	return (sign * num);
}


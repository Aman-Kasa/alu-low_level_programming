#include "main.h"

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

			if (sign == 1 && result > (2147483647U - digit) / 10)
				return (2147483647);
			if (sign == -1 && result > (2147483648U - digit) / 10)
				return (-2147483648);

			result = result * 10 + digit;
		}
		else if (digits_found)
			break;

		i++;
	}

	if (!digits_found)
		return (0);

	if (sign == -1)
		return (-(int)result); /* safe because we already handled INT_MIN case */
	return ((int)result);
}


int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int num = 0;
	int digit_found = 0;

	while (s[i])
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit_found = 1;
			unsigned int digit = s[i] - '0';

			if (sign == 1 && num > (2147483647 - digit) / 10)
				return 2147483647; // handle overflow
			if (sign == -1 && num > (2147483648U - digit) / 10)
				return -2147483648; // handle INT_MIN safely

			num = num * 10 + digit;
		}
		else if (digit_found)
			break; // stop at first non-digit after number
		i++;
	}

	return (int)(sign * (int)num);
}


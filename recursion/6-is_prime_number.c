#include "main.h"

/**
 * _is_prime - helper to check prime
 * @n: number
 * @i: current divisor
 * Return: 1 if prime, 0 otherwise
 */
int _is_prime(int n, int i)
{
	if (n < 2)
		return (0);
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (_is_prime(n, i + 1));
}

/**
 * is_prime_number - returns 1 if prime, 0 otherwise
 * @n: input number
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	return (_is_prime(n, 2));
}


#include "main.h"

/**
 * _is_prime_helper - recursive check for prime
 * @n: number
 * @i: current divisor
 * Return: 1 if prime, 0 if not
 */
int _is_prime_helper(int n, int i)
{
    if (i >= n)
        return (1);
    if (n % i == 0)
        return (0);
    return (_is_prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, else 0
 * @n: input number
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
    if (n <= 1)
        return (0);
    return (_is_prime_helper(n, 2));
}


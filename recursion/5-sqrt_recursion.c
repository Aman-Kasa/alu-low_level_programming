#include "main.h"

/**
 * _sqrt_helper - helper for sqrt recursion
 * @n: input number
 * @i: current guess
 * Return: sqrt(n) or -1 if none
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns natural sqrt of n
 * @n: input number
 * Return: sqrt(n) or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}


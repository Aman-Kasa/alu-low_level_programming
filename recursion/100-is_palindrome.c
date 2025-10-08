#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: input string
 *
 * Return: length of string
 */
		int _strlen_recursion(char *s)
{
	if (*s == '\0')
        return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * _is_palindrome_helper - helper to check palindrome
 * @s: string
 * @i: start index
 * @j: end index
 *
 * Return: 1 if palindrome, 0 if not
 */
		int _is_palindrome_helper(char *s, int i, int j)
{
	if (i >= j)
        return (1);
	if (s[i] != s[j])
        return (0);

	return (_is_palindrome_helper(s, i + 1, j - 1));
}

/**
 * is_palindrome - returns 1 if string is a palindrome, 0 otherwise
 * @s: input string
 *
 * Return: 1 if palindrome, 0 if not
 */
		int is_palindrome(char *s)
{
	int len;

	if (!s)
        return (0);

	len = _strlen_recursion(s);
	return (_is_palindrome_helper(s, 0, len - 1));
}


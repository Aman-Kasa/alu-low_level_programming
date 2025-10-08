#include "main.h"

/**
 * _strlen - returns length of string
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

/**
 * _palindrome_check - helper
 * @s: string
 * @i: start
 * @j: end
 * Return: 1 if palindrome, 0 otherwise
 */
int _palindrome_check(char *s, int i, int j)
{
	if (i >= j)
		return (1);
	if (s[i] != s[j])
		return (0);
	return (_palindrome_check(s, i + 1, j - 1));
}

/**
 * is_palindrome - returns 1 if string is palindrome
 * @s: input string
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	return (_palindrome_check(s, 0, len - 1));
}


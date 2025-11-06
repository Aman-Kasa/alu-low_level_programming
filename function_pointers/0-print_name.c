#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: the name to print
 * @f: pointer to a function that takes a string and prints it
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != 0 && f != 0)
		f(name);
}


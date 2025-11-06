#include <stddef.h>
#include "3-calc.h"

/**
 * get_op_func - selects the correct function for the operation
 * @s: operator as a string
 *
 * Return: pointer to corresponding function, or NULL if invalid
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (*s == *(ops[i].op) && *(s + 1) == '\0')
			return (ops[i].f);
		i++;
	}

	return (NULL);
}


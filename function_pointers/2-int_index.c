#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the function used to compare values
 *
 * Return: index of the first element for which cmp does not return 0,
 *         -1 if no element matches or if size <= 0 or array is NULL
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (!array || size <= 0 || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
		if (cmp(array[i]))
			return (i);

	return (-1);
}


#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h> /* for size_t */

/* Prototype for _putchar (provided by the checker) */
int _putchar(char c);

/* Prototype for print_name function */
void print_name(char *name, void (*f)(char *));

/* Prototype for array_iterator (Task 1) */
void array_iterator(int *array, size_t size, void (*action)(int));

/* Prototype for int_index (Task 2) */
int int_index(int *array, int size, int (*cmp)(int));


#endif /* FUNCTION_POINTERS_H */


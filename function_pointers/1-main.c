#include <stdio.h>
#include "function_pointers.h"

/* Function to print an element */
void print_elem(int elem)
{
    printf("%d\n", elem);
}

/* Function to print an element in hexadecimal */
void print_elem_hex(int elem)
{
    printf("0x%x\n", elem);
}

int main(void)
{
    int array[5] = {0, 98, 402, 1024, 4096};

    array_iterator(array, 5, &print_elem);
    array_iterator(array, 5, &print_elem_hex);

    return (0);
}


#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for init_dog
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    /* Initialize the dog using your function */
    init_dog(&my_dog, "Poppy", 3.5, "Bob");

    /* Print the initialized values to verify */
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    
    return (0);
}


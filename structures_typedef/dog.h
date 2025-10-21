#ifndef DOG_H
#define DOG_H

#include <stddef.h> /* for NULL */

/**
 * struct dog - represents a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Task 1: initialize a dog */
void init_dog(struct dog *d, char *name, float age, char *owner);

/* Task 2: print a dog */
void print_dog(struct dog *d);

/* Task 3: typedef dog_t as alias for struct dog */
typedef struct dog dog_t;

/* Task 4: create a new dog (allocates memory) */
dog_t *new_dog(char *name, float age, char *owner);

/* Task 5: free a dog */
void free_dog(dog_t *d);

#endif /* DOG_H */


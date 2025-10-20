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

/* Task 1: initialize a dog
  init_dog - initializes a variable of type struct dog
  @d: pointer to the struct dog to initialize
  @name: name of the dog
  @age: age of the dog
  @owner: owner of the dog*/
void init_dog(struct dog *d, char *name, float age, char *owner);

/* Task 2: print a dog 
  print_dog - prints a struct dog
  @d: pointer to struct dog
 
  If an element of d is NULL, print (nil) instead.
  If d is NULL, print nothing.*/
void print_dog(struct dog *d);

/* Task 3: typedef dog_t as alias for struct dog 
  new_dog - creates a new dog
  @name: name of the dog
  @age: age of the dog
  @owner: owner of the dog
 
  Return: pointer to the new dog, or NULL on failure*/
typedef struct dog dog_t;

/* Task 4: create a new dog (allocates memory) 
  free_dog - frees memory allocated for a dog
  @d: pointer to the dog to free
 */
dog_t *new_dog(char *name, float age, char *owner);

/* Task 5: free a dog */
void free_dog(dog_t *d);

#endif /* DOG_H */


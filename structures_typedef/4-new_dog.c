#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog structure
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL if malloc fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *name_copy, *owner_copy;
	int i, len;

    /* Allocate memory for dog structure */
	d = malloc(sizeof(dog_t));
	if (!d)
	return (NULL);

    /* Allocate and copy name */
	for (len = 0; name[len] != '\0'; len++);

	name_copy = malloc(len + 1);
	if (!name_copy)
    {
	free(d);
	return (NULL);
    }
	for (i = 0; i <= len; i++)
	name_copy[i] = name[i];

    /* Allocate and copy owner */
	for (len = 0; owner[len] != '\0'; len++);

	owner_copy = malloc(len + 1);
	if (!owner_copy)
    {
	free(name_copy);
	free(d);
	return (NULL);
    }
    for (i = 0; i <= len; i++)
        owner_copy[i] = owner[i];

    /* Set dog fields */
    d->name = name_copy;
    d->age = age;
    d->owner = owner_copy;

    return (d);
}
/**
 * free_dog - frees memory allocated for a dog
 * @d: pointer to dog to free
 */
void free_dog(dog_t *d)
{
    if (d)
    {
        if (d->name)
            free(d->name);
        if (d->owner)
            free(d->owner);
        free(d);
    }
}


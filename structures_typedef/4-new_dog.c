#include <stdlib.h>
#include "dog.h"

/**
 * copy_string - duplicates a string
 * @str: string to copy
 *
 * Return: pointer to new string, or NULL if malloc fails
 */
char *copy_string(char *str)
{
	int i, len;
	char *copy;

	len = 0;
	while (str[len] != '\0')
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	for (i = 0; i <= len; i++)
		copy[i] = str[i];
	return (copy);
}

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

	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);

	d->name = copy_string(name);
	if (!d->name)
	{
		free(d);
		return (NULL);
	}

	d->owner = copy_string(owner);
	if (!d->owner)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;

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


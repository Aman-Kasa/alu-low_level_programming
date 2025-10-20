# C - Structures, typedef

## Project Overview

This project focuses on understanding **C structures** and **typedef**. You will learn how to:

- Define and use structures in C.
- Initialize structure variables using functions.
- Print structure contents with proper formatting.
- Use `typedef` to create aliases for structures.
- Dynamically allocate and free memory for structures safely.

---

## Learning Objectives

At the end of this project, you should be able to:

1. Explain what a structure is, and when and why to use it.
2. Initialize structures using functions.
3. Print the contents of a structure.
4. Use `typedef` to simplify structure type names.
5. Dynamically create and free structures while avoiding memory leaks.
6. Follow **Betty coding style** in all files.

---

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`.
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files must end with a new line.
- No global variables allowed.
- Maximum 5 functions per file.
- Only allowed C standard library functions: `printf`, `malloc`, `free`, `exit`.
- Header files must be include-guarded and documented.

---

## File Overview

| File | Purpose |
|------|---------|
| `dog.h` | Header file for struct `dog` and typedef `dog_t`. Contains prototypes of all functions. |
| `0-main.c` | Example code for defining a `struct dog`. |
| `0-dog.c` | Defines the struct `dog`. |
| `1-init_dog.c` | Initializes a `struct dog` with values. |
| `2-print_dog.c` | Prints the contents of a `struct dog`. Handles `NULL` values. |
| `3-main.c` | Demonstrates typedef usage with `dog_t`. |
| `4-new_dog.c` | Dynamically allocates and initializes a new `dog_t`. |
| `5-free_dog.c` | Frees memory allocated for a `dog_t`. |

---

## Structures

```c
/**
 * struct dog - A dog structure
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the owner
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};
c
Copy code
typedef struct dog dog_t;
Function Prototypes
c
Copy code
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
init_dog: Initializes an existing dog structure.

print_dog: Prints a dog’s details; prints (nil) if a field is NULL.

new_dog: Allocates memory for a new dog structure and copies strings.

free_dog: Frees all allocated memory for a dog structure.

Compilation
To compile each main file with its corresponding function:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-dog.c -o 0-dog
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-init_dog.c -o 1-init_dog
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-print_dog.c -o 2-print_dog
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 0-dog.c -o 3-typedef
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-new_dog.c -o 4-new_dog
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-main.c 4-new_dog.c 5-free_dog.c -o 5-free_dog
Example Output
bash
Copy code
$ ./4-new_dog
My name is Poppy, and I am 3.5 :) - Woof!

$ valgrind ./5-free_dog
==12345== All heap blocks were freed -- no leaks are possible
GitHub Workflow
Create the repository:

bash
Copy code
git init
git remote add origin <your_repo_url>
Add files:

bash
Copy code
git add dog.h 0-dog.c 1-init_dog.c 2-print_dog.c 4-new_dog.c 5-free_dog.c 0-main.c 1-main.c 2-main.c 3-main.c 4-main.c 5-main.c README.md
Commit files:

bash
Copy code
git commit -m "Complete C - Structures typedef project: structs, typedef, init, print, new, free"
Push to GitHub:

bash
Copy code
git branch -M main
git push -u origin main
Betty Style Compliance
All functions have a single responsibility.

Functions and header files are properly documented.

No more than 5 functions per file.

No global variables.

Correct indentation, spacing, and naming conventions.

Author
Your Name – ALU Low-Level Programming Student

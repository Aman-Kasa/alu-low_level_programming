[Malloc free](https://imgs.search.brave.com/QFedK6ro5OO-kMS_L1wptqi4G7-HYwSsWxEt-p65LCY/rs:fit:500:0:1:0/g:ce/aHR0cHM6Ly9kb3Ru/ZXR0cmlja3NjbG91/ZC5ibG9iLmNvcmUu/d2luZG93cy5uZXQv/YXJ0aWNsZS81NjIw/MjUwODAyMTM0NzQ5/LndlYnA)

📘 C - malloc, free
🧠 Overview

This project is part of the Low-Level Programming module at ALU (African Leadership University).
It focuses on dynamic memory allocation in C — specifically how to use malloc and free safely and effectively.
By completing this project, I developed a deeper understanding of how memory is managed in C and how to write efficient, leak-free programs.
-----------------------------------------------------------------------------------------------------------------------
🎯 Learning Objectives

**By the end of this project, I was able to:

1. Explain the difference between automatic and dynamic memory allocation

2. Understand how and when to use malloc and free

3. Detect and fix memory leaks using tools like Valgrind

4. Implement real C functions that rely on manual memory management

Follow the Betty coding style and compile with strict flags for robust code quality
-----------------------------------------------------------------------------------------------------------------
⚙️ Technologies & Tools

Language: C (C89 Standard)

OS: Ubuntu 20.04 LTS

Compiler: gcc -Wall -Werror -Wextra -pedantic -std=gnu89

Code Style: Betty

Memory Checking: Valgrind
---------------------------------------------------------------------------------------------------------------------
📂 Project Structure
alu-low_level_programming/
│
├── malloc_free/
│   ├── 0-create_array.c
│   ├── 1-strdup.c
│   ├── 2-str_concat.c
│   ├── 3-alloc_grid.c
│   ├── 4-free_grid.c
│   ├── 100-argstostr.c
│   ├── 101-strtow.c
│   ├── main.h
│   ├── README.md
│   └── (Test files not pushed to repo)
------------------------------------------------------------------------------------------------------------------
🧩 Tasks Summary
0. Float like a butterfly, sting like a bee

Create an array of chars and initialize it with a specific character.
Prototype: char *create_array(unsigned int size, char c);

✅ Mastered memory initialization and pointer validation.

1. The woman who has no imagination has no wings

Duplicate a string using malloc.
Prototype: char *_strdup(char *str);

✅ Implemented custom string duplication without using strdup.

2. He who is not courageous enough to take risks will accomplish nothing in life

Concatenate two strings into a new dynamically allocated string.
Prototype: char *str_concat(char *s1, char *s2);

✅ Practiced handling NULL inputs and pointer arithmetic.

3. If you even dream of beating me you'd better wake up and apologize

Allocate a 2D grid of integers and initialize all elements to 0.
Prototype: int **alloc_grid(int width, int height);

✅ Learned to allocate multi-dimensional arrays dynamically.

4. It’s not bragging if you can back it up

Free a previously allocated 2D grid.
Prototype: void free_grid(int **grid, int height);

✅ Reinforced best practices in memory deallocation.

5. It isn’t the mountains ahead to climb that wear you out; it’s the pebble in your shoe

Concatenate all arguments of a program into one string separated by \n.
Prototype: char *argstostr(int ac, char **av);

✅ Deepened understanding of dynamic string construction from multiple inputs.

6. I will show you how great I am

Split a string into words.
Prototype: char **strtow(char *str);

✅ Built a complete string tokenizer using manual memory allocation and pointer arrays.
-----------------------------------------------------------------------------------------------------------------
🧪 Memory Validation

All functions were tested using Valgrind to ensure there are no memory leaks or invalid accesses.

Example output:

==5013== All heap blocks were freed -- no leaks are possible
==5013== ERROR SUMMARY: 0 errors from 0 contexts
--------------------------------------------------------------------------------------------------------------------
🏆 Achievements

## Project completion score: 100%

## All tasks passed (mandatory + advanced)

## No memory leaks detected

## Betty style fully compliant
---------------------------------------------------------------------------------------------------------------------
📚 Key Takeaways

* Mastered manual memory control using malloc and free

* Gained confidence working with pointers and dynamic data structures

* Learned to use Valgrind effectively for memory debugging

* Reinforced principles of robust, leak-free C programming
---------------------------------------------------------------------------------------------------------------
👨‍💻 Author

Aman Abraha Kasa
🖥️ Low-Level Programming Student @ ALU
📍 Focused on systems programming, operating systems, and blockchain core development
🔗 GitHub: https://github.com/Aman-Kasa
--------------------------------------------------------------------------------------------------------------------

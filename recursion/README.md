# C - Recursion

## Project Overview
This project contains a set of recursive functions implemented in C as part of the ALU Low-Level Programming course. The goal is to learn how recursion works, when to use it, and how to implement recursive solutions without using loops or global/static variables.

---

## Learning Objectives
By the end of this project, you should be able to:

- Explain what recursion is.
- Implement recursive functions in C.
- Identify situations where recursion is appropriate.
- Identify situations where recursion should be avoided.

---

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on Ubuntu 20.04 LTS using GCC with options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files end with a new line
- Code follows Betty style (checked using `betty-style.pl` and `betty-doc.pl`)
- No global variables
- No more than 5 functions per file
- No loops (`for`, `while`, `do-while`)
- No static variables
- No standard library functions (`printf`, `puts`, etc.), except `_putchar`

---

## Project Structure

recursion/
├── _putchar.c
├── main.h
├── 0-puts_recursion.c
├── 0-main.c
├── 1-print_rev_recursion.c
├── 1-main.c
├── 2-strlen_recursion.c
├── 2-main.c
├── 3-factorial.c
├── 3-main.c
├── 4-pow_recursion.c
├── 4-main.c
├── 5-sqrt_recursion.c
├── 5-main.c
├── 6-is_prime_number.c
├── 6-main.c
└── README.md



---

## Functions Implemented

| Task | Function | Prototype | Description |
|------|----------|-----------|-------------|
| 0 | `_puts_recursion` | `void _puts_recursion(char *s);` | Prints a string followed by a new line recursively |
| 1 | `_print_rev_recursion` | `void _print_rev_recursion(char *s);` | Prints a string in reverse recursively |
| 2 | `_strlen_recursion` | `int _strlen_recursion(char *s);` | Returns the length of a string recursively |
| 3 | `factorial` | `int factorial(int n);` | Returns the factorial of a number |
| 4 | `_pow_recursion` | `int _pow_recursion(int x, int y);` | Returns x raised to the power y |
| 5 | `_sqrt_recursion` | `int _sqrt_recursion(int n);` | Returns the natural square root of a number |
| 6 | `is_prime_number` | `int is_prime_number(int n);` | Returns 1 if number is prime, else 0 |

---

## Compilation Instructions
Compile each task with its main file (and `_putchar.c` if needed). Examples:

```bash
# Task 0
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-puts_recursion.c 0-main.c -o 0-puts_recursion

# Task 1
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 1-print_rev_recursion.c 1-main.c -o 1-print_rev_recursion

# Task 2
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-strlen_recursion.c 2-main.c -o 2-strlen_recursion

# Task 3
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-factorial.c 3-main.c -o 3-factorial

# Task 4
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 4-pow_recursion.c 4-main.c -o 4-pow

# Task 5
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-sqrt_recursion.c 5-main.c -o 5-sqrt

# Task 6
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 6-is_prime_number.c 6-main.c -o 6-prime



######Run the executable:

./0-puts_recursion
./1-print_rev_recursion
./2-strlen_recursion
./3-factorial
./4-pow
./5-sqrt
./6-prime






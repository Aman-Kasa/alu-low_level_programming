![C - Recursion](https://imgs.search.brave.com/Z9PgVQ0oevafqX1xLwntK5ygQc-JO1ovBhhcAvKCHuY/rs:fit:500:0:1:0/g:ce/aHR0cHM6Ly93d3cu/ZnJlZWNvZGVjYW1w/Lm9yZy9uZXdzL2Nv/bnRlbnQvaW1hZ2Vz/L3NpemUvdzIwMDAv/MjAyMS8wNy9yZWN1/cnNpb24ucG5n)

######Project Overview

- This project is part of the ALX Low-Level Programming curriculum and focuses on recursion in C. Recursion is a technique where a function calls itself to solve smaller instances of a problem until a base case is reached.

- The goal of this project is to implement several recursive functions without using loops, static variables, or standard library functions, except for _putchar for output. Each function demonstrates a fundamental recursive concept, ranging from simple string manipulation to advanced problem-solving tasks.

- All code follows Betty coding style and is compiled on Ubuntu 20.04 LTS using strict GCC flags.
-------------------------------------------------------------------------------------------------------------------------------
##Project Structure

recursion/
│
├─ _putchar.c             # Function to print a single character
├─ main.h                 # Header file with function prototypes
├─ 0-puts_recursion.c     # Prints a string recursively
├─ 0-main.c
├─ 1-print_rev_recursion.c# Prints a string in reverse recursively
├─ 1-main.c
├─ 2-strlen_recursion.c   # Returns string length recursively
├─ 2-main.c
├─ 3-factorial.c          # Computes factorial recursively
├─ 3-main.c
├─ 4-pow_recursion.c      # Computes x raised to power y recursively
├─ 4-main.c
├─ 5-sqrt_recursion.c     # Computes natural square root recursively
├─ 5-main.c
├─ 6-is_prime_number.c    # Checks if a number is prime recursively
├─ 6-main.c
├─ 100-is_palindrome.c    # Checks if a string is a palindrome recursively
├─ 100-main.c
├─ 101-wildcmp.c          # Compares strings with wildcard (*) recursively
├─ 101-main.c
├─ compile_all.sh         # Bash script to compile all tasks at once
└─ README.md              # Project documentation

--------------------------------------------------------------------------------------------------------------------------------
##Compilation
- Using the Bash Script

- The provided compile_all.sh script compiles all tasks and generates executables:
	- chmod +x compile_all.sh
	- ./compile_all.sh


##Executables generated:
0-puts, 1-rev, 2-strlen, 3-fact, 4-pow, 5-sqrt, 6-prime, 100-pal, 101-wild

##Manual Compilation Example
- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts
- ./0-puts

##Replace 0-main.c and 0-puts_recursion.c with the corresponding files for other tasks.
-----------------------------------------------------------------------------------------------------------------------------

## Tasks Summary

| Task | Description                                | Function Prototype                     | Example Output            |
|------|-------------------------------------------|---------------------------------------|---------------------------|
| 0    | Print a string recursively                 | `void _puts_recursion(char *s);`      | `Puts with recursion`     |
| 1    | Print a string in reverse recursively     | `void _print_rev_recursion(char *s);` | `reklaW notloC`           |
| 2    | Return string length recursively           | `int _strlen_recursion(char *s);`     | `14`                      |
| 3    | Return factorial of a number recursively  | `int factorial(int n);`               | `120` for 5!              |
| 4    | Compute x raised to power y recursively   | `int _pow_recursion(int x, int y);`   | `65536` for 2^16          |
| 5    | Compute natural square root recursively   | `int _sqrt_recursion(int n);`         | `4` for 16                |
| 6    | Check if number is prime recursively      | `int is_prime_number(int n);`         | `1` if prime, `0` otherwise|
| 100  | Check if string is palindrome recursively| `int is_palindrome(char *s);`         | `1` for "level"           |
| 101  | Compare strings with wildcard recursively | `int wildcmp(char *s1, char *s2);`   | `1` if matches, supports `*` |
--------------------------------------------------------------------------------------------------------------------------------

##Usage Examples
./0-puts
./1-rev
./2-strlen
./3-fact
./4-pow
./5-sqrt
./6-prime
./100-pal
./101-wild

- >>>>>>>Each program can be tested using its corresponding main.c file.
-----------------------------------------------------------------------------------------------------------------------------------
##Key Concepts
- Recursion: Function calls itself with a smaller problem instance. Each recursive function has:
	- A base case: stops recursion.
	- A recursive step: reduces the problem toward the base case.

- Restrictions:
	- No loops (for, while, do-while)
	- No static variables
	- No standard library functions (except _putchar for output)

##Compilation Flags

- All files are compiled with the following GCC flags:

-Wall -Werror -Wextra -pedantic -std=gnu89

>> These ensure code quality, adherence to C89 standard, and strict warning/error checks.

-------------------------------------------------------------------------------------------------
##Author											|
												|
##Aman Kasa – ALU Low-Level Programming								|
##GitHub Repository: https://github.com/Aman-Kasa/alu-low_level_programming.git			|
-------------------------------------------------------------------------------------------------

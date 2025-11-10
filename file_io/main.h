#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>

/* Prototype for 0-read_textfile.c */
ssize_t read_textfile(const char *filename, size_t letters);

/* Prototype for 1-create_file.c */
int create_file(const char *filename, char *text_content);

/* Prototype for _putchar if used elsewhere */
int _putchar(char c);

#endif /* MAIN_H */


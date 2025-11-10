#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "main.h"

/**
 * error_exit - prints an error message and exits with a code
 * @msg: message to print
 * @fd: file descriptor value or -1 if unused
 * @exit_code: code to exit with
 */
void error_exit(char *msg, int fd, int exit_code)
{
	if (fd >= 0)
		dprintf(STDERR_FILENO, "%s %d\n", msg, fd);
	else
		dprintf(STDERR_FILENO, "%s\n", msg);
	exit(exit_code);
}

/**
 * main - copies the content of one file to another
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r_bytes, w_bytes;
	char buffer[1024];

	if (ac != 3)
		error_exit("Usage: cp file_from file_to", -1, 97);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit("Error: Can't read from file", -1, 98);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit("Error: Can't write to", -1, 99);
	}

	while ((r_bytes = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			error_exit("Error: Can't write to", -1, 99);
		}
	}

	if (r_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit("Error: Can't read from file", -1, 98);
	}

	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}


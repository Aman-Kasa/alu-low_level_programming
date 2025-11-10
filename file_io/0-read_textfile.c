#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: The actual number of letters read and printed,
 *         or 0 if file cannot be opened, read, or write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buffer;

	if (!filename || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}

	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	n_written = write(STDOUT_FILENO, buffer, n_read);
	if (n_written != n_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (n_written);
}


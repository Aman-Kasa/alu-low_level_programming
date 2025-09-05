#include <unistd.h>

/**
 * main - Prints the quote to standard error
 *
 * Return: 1 (Failure)
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - Dora Korpar, ", 48);
	write(2, "2015-10-19\n", 11);
	return (1);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - prints an error message to stderr and exits
 * @msg: message to print
 */
void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_magic - prints ELF magic numbers
 * @e_ident: the ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * main - displays the ELF header of a file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't read from file");

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Error: Can't read ELF header");

	/* Check ELF magic */
	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
	    e_ident[2] != 'L' || e_ident[3] != 'F')
		print_error("Error: Not an ELF file");

	printf("ELF Header:\n");
	print_magic(e_ident);

	/* Seek back and read full header */
	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Error: Can't read ELF header");

	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
		print_error("Error: Can't read ELF header");

	/* Class */
	printf("  Class:                             %s\n",
	       e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	/* Data */
	printf("  Data:                              %s endian\n",
	       e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little" :
	       "2's complement, big");

	/* Version */
	printf("  Version:                           %d (current)\n",
	       e_ident[EI_VERSION]);

	/* OS/ABI */
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		default: printf("<unknown: %d>\n", e_ident[EI_OSABI]);
	}

	/* ABI Version */
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	/* Type */
	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %x>\n", header.e_type);
	}

	/* Entry point */
	printf("  Entry point address:               0x%lx\n",
	       (unsigned long)header.e_entry);

	if (close(fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd), exit(98);

	return (0);
}


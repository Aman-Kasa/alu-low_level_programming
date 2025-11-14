#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - prints an error message and exits
 * @msg: error message
 * @file: filename (can be NULL)
 */
void print_error(char *msg, char *file)
{
	if (file)
		dprintf(STDERR_FILENO, "Error: %s %s\n", msg, file);
	else
		dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * swap16 - swap bytes for 16-bit big endian
 * @val: value
 * Return: swapped value
 */
unsigned short swap16(unsigned short val)
{
	return ((val >> 8) | (val << 8));
}

/**
 * swap32 - swap bytes for 32-bit big endian
 * @val: value
 * Return: swapped value
 */
unsigned int swap32(unsigned int val)
{
	return (((val >> 24) & 0xff) |
	        ((val >> 8) & 0xff00) |
	        ((val << 8) & 0xff0000) |
	        ((val << 24) & 0xff000000));
}

/**
 * print_magic - prints ELF magic
 * @e_ident: ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * get_osabi - returns OS/ABI string
 * @osabi: byte value
 * Return: string
 */
const char *get_osabi(unsigned char osabi)
{
	switch (osabi)
	{
	case ELFOSABI_SYSV: return "UNIX - System V";
	case ELFOSABI_HPUX: return "HP-UX";
	case ELFOSABI_NETBSD: return "UNIX - NetBSD";
	case ELFOSABI_LINUX: return "UNIX - Linux";
	case ELFOSABI_SOLARIS: return "UNIX - Solaris";
	case ELFOSABI_IRIX: return "IRIX";
	case ELFOSABI_FREEBSD: return "UNIX - FreeBSD";
	case ELFOSABI_TRU64: return "TRU64 UNIX";
	case ELFOSABI_ARM: return "ARM";
	case ELFOSABI_STANDALONE: return "Standalone App";
	default: return "<unknown>";
	}
}

/**
 * get_type - returns type string
 * @type: e_type value
 * Return: string
 */
const char *get_type(unsigned short type)
{
	switch (type)
	{
	case ET_NONE: return "NONE (None)";
	case ET_REL: return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN: return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default: return "<unknown>";
	}
}

/**
 * main - displays ELF header info
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr h64;
	Elf32_Ehdr h32;
	int is_64;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename", NULL);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't read from file", argv[1]);

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Can't read from file", argv[1]);

	/* Verify ELF magic */
	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file", argv[1]);

	is_64 = (e_ident[EI_CLASS] == ELFCLASS64);

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Can't read from file", argv[1]);

	if (is_64)
	{
		if (read(fd, &h64, sizeof(h64)) != sizeof(h64))
			print_error("Can't read from file", argv[1]);
	}
	else
	{
		if (read(fd, &h32, sizeof(h32)) != sizeof(h32))
			print_error("Can't read from file", argv[1]);
	}

	printf("ELF Header:\n");
	print_magic(e_ident);

	printf("  Class:                             %s\n",
	       (e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");

	printf("  Data:                              %s\n",
	       (e_ident[EI_DATA] == ELFDATA2LSB) ?
	       "2's complement, little endian" : "2's complement, big endian");

	printf("  Version:                           %d\n", e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", get_osabi(e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	if (is_64)
	{
		unsigned short type = h64.e_type;
		if (e_ident[EI_DATA] == ELFDATA2MSB)
			type = swap16(type);

		printf("  Type:                              %s\n", get_type(type));
		printf("  Entry point address:               %#lx\n",
		       (unsigned long)h64.e_entry);
	}
	else
	{
		unsigned short type = h32.e_type;
		unsigned int entry = h32.e_entry;

		if (e_ident[EI_DATA] == ELFDATA2MSB)
		{
			type = swap16(type);
			entry = swap32(entry);
		}

		printf("  Type:                              %s\n", get_type(type));
		printf("  Entry point address:               %#x\n", entry);
	}

	close(fd);
	return (0);
}


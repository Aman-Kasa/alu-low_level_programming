#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * elf_header - Displays the ELF header info of a given file
 * @filename: Name of the ELF file
 */
void elf_header(const char *filename)
{
	int fd;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		close(fd);
		dprintf(2, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	if (e_ident[EI_MAG0] != 0x7f || e_ident[EI_MAG1] != 'E' ||
	    e_ident[EI_MAG2] != 'L' || e_ident[EI_MAG3] != 'F')
	{
		close(fd);
		dprintf(2, "Error: %s is not an ELF file\n", filename);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");

	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		default: printf("<unknown: %d>\n", e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		dprintf(2, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr ehdr32;
		if (read(fd, &ehdr32, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
		{
			close(fd);
			dprintf(2, "Error: Can't read from file %s\n", filename);
			exit(98);
		}
		printf("  Type:                              ");
		switch (ehdr32.e_type)
		{
			case ET_NONE: printf("NONE (None)\n"); break;
			case ET_REL: printf("REL (Relocatable file)\n"); break;
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_DYN: printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default: printf("<unknown>\n");
		}
		printf("  Entry point address:               0x%x\n", ehdr32.e_entry);
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr ehdr64;
		if (read(fd, &ehdr64, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		{
			close(fd);
			dprintf(2, "Error: Can't read from file %s\n", filename);
			exit(98);
		}
		printf("  Type:                              ");
		switch (ehdr64.e_type)
		{
			case ET_NONE: printf("NONE (None)\n"); break;
			case ET_REL: printf("REL (Relocatable file)\n"); break;
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_DYN: printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default: printf("<unknown>\n");
		}
		printf("  Entry point address:               0x%lx\n", ehdr64.e_entry);
	}

	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}


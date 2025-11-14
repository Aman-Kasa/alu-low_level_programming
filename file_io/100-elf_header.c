#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/* exit + print error */
void print_error(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/* Print OS/ABI */
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
	default:
	{
		static char buf[32];
		snprintf(buf, sizeof(buf), "<unknown: %x>", osabi);
		return buf;
	}
	}
}

/* Print type */
const char *get_type(uint16_t t)
{
	switch (t)
	{
	case ET_NONE: return "NONE (None)";
	case ET_REL: return "REL (Relocatable file)";
	case ET_EXEC: return "EXEC (Executable file)";
	case ET_DYN: return "DYN (Shared object file)";
	case ET_CORE: return "CORE (Core file)";
	default:
	{
		static char buf[32];
		snprintf(buf, sizeof(buf), "<unknown: %x>", t);
		return buf;
	}
	}
}

int main(int argc, char *argv[])
{
	int fd, r;
	unsigned char e_ident[EI_NIDENT];
	Elf64_Ehdr h64;
	Elf32_Ehdr h32;
	int is_64;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't read file");

	/* 1st read: e_ident */
	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
		print_error("Error: Can't read file");

	/* verify ELF magic */
	if (e_ident[EI_MAG0] != ELFMAG0 ||
		e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 ||
		e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file");

	is_64 = (e_ident[EI_CLASS] == ELFCLASS64);

	/* lseek once */
	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Error: Can't read file");

	/* 2nd read: whole header */
	if (is_64)
	{
		if (read(fd, &h64, sizeof(h64)) != sizeof(h64))
			print_error("Error: Can't read file");
	}
	else
	{
		if (read(fd, &h32, sizeof(h32)) != sizeof(h32))
			print_error("Error: Can't read file");
	}

	/* Output formatting */
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (r = 0; r < EI_NIDENT; r++)
		printf("%02x%s", e_ident[r], r == EI_NIDENT - 1 ? "" : " ");
	printf("\n");

	printf("  Class:                             %s\n",
		(e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" :
		(e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "Unknown");

	printf("  Data:                              %s\n",
		(e_ident[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" :
		(e_ident[EI_DATA] == ELFDATA2MSB) ?
		"2's complement, big endian" : "Unknown");

	printf("  Version:                           %d (current)\n",
		e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
		get_osabi(e_ident[EI_OSABI]));

	printf("  ABI Version:                       %d\n",
		e_ident[EI_ABIVERSION]);

	if (is_64)
	{
		printf("  Type:                              %s\n",
			get_type(h64.e_type));

		printf("  Entry point address:               %#lx\n",
			(unsigned long)h64.e_entry);
	}
	else
	{
		printf("  Type:                              %s\n",
			get_type(h32.e_type));

		printf("  Entry point address:               %#x\n",
			h32.e_entry);
	}

	close(fd);
	return (0);
}


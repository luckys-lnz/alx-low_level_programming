#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 64

/**
 *check_if_elf - checks if the file is an ELF file
 *@e_ident: the identification bytes of the ELF file
 *
 *Return: void
 */
void check_if_elf(unsigned char *e_ident)
{
	/*Check if the file signature matches the ELF magic numbers */
	if (memcmp(e_ident, ELFMAG, SELFMAG) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 *print_header_info - prints the information in the ELF header
 *@header: pointer to the ELF header structure
 *
 *Return: void
 */
void print_header_info(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");

	/*Print the magic numbers */
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	/*Print the class of the ELF file */
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
			break;
	}

	/*Print the data encoding of the ELF file */
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
			break;
	}

	/*Print the version of the ELF file */
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

	/*Print the OS/ABI of the ELF file */
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
			break;
	}

	/*Print the ABI version of the ELF file */
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

	/*Print the type of the ELF file */
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_type);
			break;
	}

	/*Print the entry point address of the ELF file */
	printf("  Entry point address:               %#lx\n", header->e_entry);
}

/**
 *main - Entry point
 *@argc: argument count
 *@argv: argument vector
 *
 *Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	/*Check the number of command-line arguments */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (98);
	}

	/*Open the ELF file for reading */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (98);
	}

	/*Read the ELF header into memory */
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	/*Check if the file is an ELF file */
	check_if_elf(header.e_ident);

	/*Print the information in the ELF header */
	print_header_info(&header);

	/*Close the file */
	close(fd);

	return (0);
}

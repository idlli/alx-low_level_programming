#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf_(unsigned char *e_ident);
void print_magic_(unsigned char *e_ident);
void print_class_(unsigned char *e_ident);
void print_data_(unsigned char *e_ident);
void print_version_(unsigned char *e_ident);
void print_abi_(unsigned char *e_ident);
void print_osabi_(unsigned char *e_ident);
void print_type_(unsigned int e_type, unsigned char *e_ident);
void print_entry_(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_(int elf);

void check_elf_(unsigned char *e_ident) {
    int index;

    for (index = 0; index < 4; index++) {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F') {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

void print_magic_(unsigned char *e_ident) {
    int index;
    printf("  Magic:   ");

    for (index = 0; index < EI_NIDENT; index++) {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}

void print_class_(unsigned char *e_ident) {
    printf("  Class:                             ");

    switch (e_ident[EI_CLASS]) {
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
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data_(unsigned char *e_ident) {
    printf("  Data:                              ");

    switch (e_ident[EI_DATA]) {
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
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_version_(unsigned char *e_ident) {
    printf("  Version:                           %d", e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION]) {
        case EV_CURRENT:
            printf(" (current)\n");
            break;
        default:
            printf("\n");
            break;
    }
}

void print_osabi_(unsigned char *e_ident) {
	printf(" OS/ABI: ");
	switch (e_ident[EI_OSABI]) {
		case ELFOSABI_NONE:
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

void print_abi_(unsigned char *e_ident) {
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

void print_type_(unsigned int e_type, unsigned char *e_ident) {
	if (e_ident[EI_DATA] == ELFDATA2MSB) {
		e_type >>= 8;
	}
	printf(" Type: ");
	switch (e_type) {
		case ET_NONE:
			printf("NONE (None)\n");
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
			printf("<unknown: %x>\n", e_type);
	}
}

void print_entry_(unsigned long int e_entry, unsigned char *e_ident) {
	printf(" Entry point address: ");
	if (e_ident[EI_DATA] == ELFDATA2MSB) {
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32) {
		printf("%#x\n", (unsigned int)e_entry);
	} else {
		printf("%#lx\n", e_entry);
	}
}

void close_elf_(int elf) {
	if (close(elf) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int _op, _re;

	_op = open(argv[1], O_RDONLY);
	if (_op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_(_op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	_re = read(_op, header, sizeof(Elf64_Ehdr));
	if (_re == -1)
	{
		free(header);
		close_elf_(_op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf_(header->e_ident);
	printf("ELF Header:\n");
	print_magic_(header->e_ident);
	print_class_(header->e_ident);
	print_data_(header->e_ident);
	print_version_(header->e_ident);
	print_osabi_(header->e_ident);
	print_abi_(header->e_ident);
	print_type_(header->e_type, header->e_ident);
	print_entry_(header->e_entry, header->e_ident);

	free(header);
	close_elf_(_op);
	return (0);
}
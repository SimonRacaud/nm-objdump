/*
** EPITECH PROJECT, 2021
** src
** File description:
** header.c, Thursday, 1st January 1970 1:00:00 am simon.racaud@epitech.eu
*/

#include "nm.h"

// typedef struct {
//     unsigned char e_ident[EI_NIDENT]; /* Magic number and other info */
//     Elf64_Half e_type;                /* Object file type */
//     Elf64_Half e_machine;             /* Architecture */
//     Elf64_Word e_version;             /* Object file version */
//     Elf64_Addr e_entry;               /* Entry point virtual address */
//     Elf64_Off e_phoff;                /* Program header table file offset */
//     Elf64_Off e_shoff;     ---        /* Section header table file offset */
//     Elf64_Word e_flags;               /* Processor-specific flags */
//     Elf64_Half e_ehsize;              /* ELF header size in bytes */
//     Elf64_Half e_phentsize;           /* Program header table entry size */
//     Elf64_Half e_phnum;               /* Program header table entry count */
//     Elf64_Half e_shentsize;           /* Section header table entry size */
//     Elf64_Half e_shnum;    ---        /* Section header table entry count */
//     Elf64_Half e_shstrndx;   ---      /* Section header string table index
// } Elf64_Ehdr;

static bool is_valid(Elf64_Ehdr *h)
{
    if (h->e_ident[EI_MAG0] != ELFMAG0 || h->e_ident[EI_MAG1] != ELFMAG1
        || h->e_ident[EI_MAG2] != ELFMAG2 || h->e_ident[EI_MAG3] != ELFMAG3
        || (h->e_type == ET_NONE || h->e_type == ET_CORE)) {
        return false;
    }
    return true;
}

int load_elf_header(Elf64_Ehdr *header, void *file)
{
    header = file;
    return is_valid(header) ? EXIT_SUCCESS : EXIT_ERROR;
}

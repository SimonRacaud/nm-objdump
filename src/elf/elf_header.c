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

static bool is_file_truncated64(Elf64_Ehdr *h, elf_file_t *file)
{
    size_t file_size = h->e_shoff + (h->e_shnum * h->e_shentsize);

    if (file_size > file->size) {
        fprintf(stderr, "%s: %s: file truncated\n", file->app_name,
            file->filename);
        return true;
    }
    return false;
}

static bool is_file_truncated32(Elf32_Ehdr *h, elf_file_t *file)
{
    size_t file_size = h->e_shoff + (h->e_shnum * h->e_shentsize);

    if (file_size > file->size) {
        fprintf(stderr, "%s: %s: file truncated\n", file->app_name,
            file->filename);
        return true;
    }
    return false;
}

static bool is_valid(Elf64_Ehdr *h, elf_file_t *file)
{
    if (h->e_ident[EI_MAG0] != ELFMAG0 || h->e_ident[EI_MAG1] != ELFMAG1
        || h->e_ident[EI_MAG2] != ELFMAG2 || h->e_ident[EI_MAG3] != ELFMAG3
        || (h->e_type == ET_NONE || h->e_type == ET_CORE)) {
        fprintf(stderr, "%s: %s: file format not recognized\n", file->filename,
            file->filename);
        return false;
    }
    if (file->elf_head64->e_ident[EI_CLASS] == ELFCLASS64) {
        return !is_file_truncated64(h, file);
    } else if (file->elf_head64->e_ident[EI_CLASS] == ELFCLASS32) {
        return !is_file_truncated32(file->elf_head32, file);
    }
    return true;
}

int load_elf_header(elf_file_t *file)
{
    file->elf_head64 = (Elf64_Ehdr *) file->content;
    file->elf_head32 = (Elf32_Ehdr *) file->content;
    return is_valid(file->elf_head64, file) ? EXIT_SUCCESS : EXIT_ERROR;
}

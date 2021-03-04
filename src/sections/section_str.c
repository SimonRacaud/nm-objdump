/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** string table section
*/

#include "nm.h"

const char *STR_SECT = ".strtab";

char *get_str_sect64(elf_file_t *file, Elf64_Shdr *sections)
{
    if (file->elf_head.e_shstrndx == SHN_UNDEF) {
        return NULL;
    }
    if ((size_t)((char *) &sections[file->elf_head.e_shstrndx + 1]
            - (char *) &file->elf_head)
        > file->size) {
        return NULL;
    }
    return (char *) (&file->elf_head)
        + sections[file->elf_head.e_shstrndx].sh_offset;
}

char *get_str_sect32(elf_file_t *file, Elf32_Shdr *sections)
{
    if (file->elf_head.e_shstrndx == SHN_UNDEF) {
        return NULL;
    }
    if ((size_t)((char *) &sections[file->elf_head.e_shstrndx + 1]
            - (char *) &file->elf_head)
        > file->size) {
        return NULL;
    }
    return (char *) (&file->elf_head)
        + sections[file->elf_head.e_shstrndx].sh_offset;
}

char *get_strtab_sect64(elf_file_t *file, Elf64_Shdr *sections)
{
    char *section_name_list = get_str_sect64(file, sections);

    for (size_t i = 0; file->elf_head.e_shnum; i++) {
        if (strcmp(section_name_list + sections[i].sh_name, STR_SECT) == 0) {
            return (char *) (&file->elf_head) + sections[i].sh_offset;
        }
    }
    return NULL;
}

char *get_strtab_sect32(elf_file_t *file, Elf32_Shdr *sections)
{
    char *section_name_list = get_str_sect32(file, sections);

    for (size_t i = 0; file->elf_head.e_shnum; i++) {
        if (strcmp(section_name_list + sections[i].sh_name, STR_SECT) == 0) {
            return (char *) (&file->elf_head) + sections[i].sh_offset;
        }
    }
    return NULL;
}
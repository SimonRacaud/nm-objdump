/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** string table section
*/

#include "nm.h"

const char *STR_SECT = ".strtab";

char *get_str_sect64(elf_file_t *file)
{
    if (file->elf_head->e_shstrndx == SHN_UNDEF) {
        return NULL;
    }
    if ((size_t)((char *) &file->sections64[file->elf_head->e_shstrndx + 1]
            - (char *) file->elf_head)
        > file->size) {
        return NULL;
    }
    return (char *) (file->elf_head)
        + file->sections64[file->elf_head->e_shstrndx].sh_offset;
}

char *get_str_sect32(elf_file_t *file)
{
    if (file->elf_head->e_shstrndx == SHN_UNDEF) {
        return NULL;
    }
    if ((size_t)((char *) &file->sections32[file->elf_head->e_shstrndx + 1]
            - (char *) &file->elf_head)
        > file->size) {
        return NULL;
    }
    return (char *) (file->elf_head)
        + file->sections32[file->elf_head->e_shstrndx].sh_offset;
}

char *get_strtab_sect64(elf_file_t *file)
{
    char *section_name_list = get_str_sect64(file);

    for (size_t i = 0; file->elf_head->e_shnum; i++) {
        if (strcmp(section_name_list + file->sections64[i].sh_name, STR_SECT)
            == 0) {
            return (char *) (file->elf_head) + file->sections64[i].sh_offset;
        }
    }
    return NULL;
}

char *get_strtab_sect32(elf_file_t *file)
{
    char *section_name_list = get_str_sect32(file);

    for (size_t i = 0; file->elf_head->e_shnum; i++) {
        if (strcmp(section_name_list + file->sections32[i].sh_name, STR_SECT)
            == 0) {
            return (char *) (file->elf_head) + file->sections32[i].sh_offset;
        }
    }
    return NULL;
}
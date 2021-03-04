/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** en-tête de la section du tableau des symboles
*/

#include "nm.h"

// typedef struct {
//     uint32_t      st_name; // symbol name position
//     unsigned char st_info;
//     unsigned char st_other;
//     uint16_t      st_shndx;
//     Elf64_Addr    st_value;
//     uint64_t      st_size;
// } Elf64_Sym;

Elf32_Shdr *get_sym_sect_hdr32(Elf32_Shdr *section_list, elf_file_t *file)
{
    static size_t section_idx = 0;

    for (; section_idx < file->elf_head.e_shnum; section_idx++) {
        if ((size_t)((char *) &section_list[section_idx + 1]
                - (char *) &file->elf_head)
            > file->size)
            break;
        if (section_list[section_idx].sh_type == SHT_SYMTAB) {
            return &section_list[section_idx];
        }
    }
    section_idx = 0;
    return NULL;
}

Elf64_Shdr *get_sym_sect_hdr64(Elf64_Shdr *section_list, elf_file_t *file)
{
    static size_t section_idx = 0;

    for (; section_idx < file->elf_head.e_shnum; section_idx++) {
        if ((size_t)((char *) &section_list[section_idx + 1]
                - (char *) &file->elf_head)
            > file->size)
            break;
        if (section_list[section_idx].sh_type == SHT_SYMTAB) {
            return &section_list[section_idx];
        }
    }
    section_idx = 0;
    return NULL;
}

Elf64_Sym *symbol64_generator(Elf64_Shdr *sym_section)
{
    static size_t size = 0;
    static size_t idx = 0;

    if (sym_section->sh_entsize != 0) {
        size = sym_section->sh_size / sym_section->sh_entsize;
    }
    for (; idx < size; idx++) {
        return &((Elf64_Sym *) sym_section)[idx];
    }
    size = 0;
    idx = 0;
    return NULL;
}
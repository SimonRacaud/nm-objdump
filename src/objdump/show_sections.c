/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** show_sections
*/

#include "objdump.h"

static bool is_show_section(
    uint32_t sh_type, Elf64_Addr sh_addr, uint64_t sh_size)
{
    return sh_type != SHT_NOBITS && sh_size > 0
        && (sh_addr != 0
            || (sh_addr == 0 && sh_type != SHT_STRTAB && sh_type != SHT_RELA
                && sh_type != SHT_REL && sh_type != SHT_SYMTAB));
}

int show_sections64(elf_file_t *file)
{
    size_t name_idx;
    char *section_names;

    file->sections64 = get_section_header64(file->elf_head64);
    section_names = get_str_sect64(file);
    if (!file->sections64 || !section_names)
        return EXIT_ERROR;
    for (size_t i = 0; i < file->elf_head64->e_shnum; i++) {
        if (!is_show_section(file->sections64[i].sh_type,
                file->sections64[i].sh_addr, file->sections64[i].sh_size)) {
            continue;
        }
        name_idx = file->sections64[i].sh_name;
        printf("Contents of section %s:\n", &section_names[name_idx]);
        print_section_content(file->sections64[i].sh_addr,
            file->sections64[i].sh_offset, file->content,
            file->sections64[i].sh_size);
    }
    return EXIT_SUCCESS;
}

int show_sections32(elf_file_t *file)
{
    size_t name_idx;
    char *section_names;

    file->sections32 = get_section_header32(file->elf_head32);
    section_names = get_str_sect32(file);
    if (!file->sections32 || !section_names)
        return EXIT_ERROR;
    for (size_t i = 0; i < file->elf_head32->e_shnum; i++) {
        if (!is_show_section(file->sections32[i].sh_type,
                file->sections32[i].sh_addr, file->sections32[i].sh_size)) {
            continue;
        }
        name_idx = file->sections32[i].sh_name;
        printf("Contents of section %s:\n", &section_names[name_idx]);
        print_section_content(file->sections32[i].sh_addr,
            file->sections32[i].sh_offset, file->content,
            file->sections32[i].sh_size);
    }
    return EXIT_SUCCESS;
}
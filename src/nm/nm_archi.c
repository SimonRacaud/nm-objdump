/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** nm64
*/

#include "nm.h"

int nm64(elf_file_t *file)
{
    file->sections64 = get_section_header64(file->elf_head64);
    sym_list_t *list = NULL;
    size_t list_size = 0;

    if (!file->sections64)
        return EXIT_ERROR;
    file->strtab_sect = get_strtab_sect64(file);
    file->sym_head64 = get_sym_sect_hdr64(file);
    if (file->sym_head64 == NULL)
        fprintf(stderr, "nm: %s: no symbols\n", file->filename);
    while (file->sym_head64 != NULL) {
        save_elf_symbols64(file, &list, &list_size);
        file->sym_head64 = get_sym_sect_hdr64(file);
    }
    sort_symbols(&list, list_size);
    display_symbols64(list);
    sym_list_destroy(list);
    return EXIT_SUCCESS;
}

int nm32(elf_file_t *file)
{
    sym_list_t *list = NULL;
    size_t list_size = 0;

    file->sections32 = get_section_header32(file->elf_head32);
    if (!file->sections32)
        return EXIT_ERROR;
    file->strtab_sect = get_strtab_sect32(file);
    if (!file->strtab_sect)
        return EXIT_ERROR;
    file->sym_head32 = get_sym_sect_hdr32(file);
    if (file->sym_head32 == NULL)
        fprintf(stderr, "nm: %s: no symbols\n", file->filename);
    while (file->sym_head32 != NULL) {
        save_elf_symbols32(file, &list, &list_size);
        file->sym_head32 = get_sym_sect_hdr32(file);
    }
    sort_symbols(&list, list_size);
    display_symbols32(list);
    sym_list_destroy(list);
    return EXIT_SUCCESS;
}

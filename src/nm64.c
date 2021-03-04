/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** nm64
*/

#include "nm.h"

int nm64(elf_file_t *file)
{
    file->sections64 = get_section_header64(file->elf_head);
    sym_list_t *list = NULL;
    size_t list_size = 0;

    if (!file->sections64)
        return EXIT_ERROR;
    file->strtab_sect = get_strtab_sect64(file);
    file->sym_head64 = get_sym_sect_hdr64(file);
    while (file->sym_head64 != NULL) {
        save_elf_symbols64(file, &list, &list_size);
        file->sym_head64 = get_sym_sect_hdr64(file);
    }
    sort_symbols(&list);
    display_symbols(list);
    sym_list_destroy(list);
    return EXIT_SUCCESS;
}

/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** display
*/

#include "nm.h"

void save_elf_symbols64(elf_file_t *file, sym_list_t **list, size_t *list_size)
{
    Elf64_Sym *symbol;
    char *name;
    char type;

    symbol = symbol64_generator(file->sym_head64, file->content);
    while (symbol != NULL) {
        name = file->strtab_sect + symbol->st_name;
        if (name[0] != '\0' && symbol->st_info != STT_FILE) {
            type = find_sym_type64(symbol, file->sections64);
            sym_list_add(list, name, symbol->st_value, type);
            (*list_size)++;
        }
        symbol = symbol64_generator(file->sym_head64, file->content);
    }
}

void save_elf_symbols32(elf_file_t *file, sym_list_t **list, size_t *list_size)
{
    Elf32_Sym *symbol;
    char *name;
    char type;

    symbol = symbol32_generator(file->sym_head32, file->content);
    while (symbol != NULL) {
        name = file->strtab_sect + symbol->st_name;
        if (name[0] != '\0' && symbol->st_info != STT_FILE) {
            type = find_sym_type32(symbol, file->sections32);
            sym_list_add(list, name, symbol->st_value, type);
            (*list_size)++;
        }
        symbol = symbol32_generator(file->sym_head32, file->content);
    }
}
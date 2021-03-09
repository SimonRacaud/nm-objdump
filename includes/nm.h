/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include "my_elf.h"
#include "sym_list_t.h"

// nm
int my_nm(const char *filename, int argc);
int nm_show_content(elf_file_t *file, int argc);

// nm archi
int nm64(elf_file_t *file);
int nm32(elf_file_t *file);

// elf section
Elf32_Shdr *get_sym_sect_hdr32(elf_file_t *file);
Elf64_Shdr *get_sym_sect_hdr64(elf_file_t *file);

Elf64_Sym *symbol64_generator(Elf64_Shdr *sym_section, void *content);
Elf32_Sym *symbol32_generator(Elf32_Shdr *sym_section, void *content);

char *get_strtab_sect64(elf_file_t *file);
char *get_strtab_sect32(elf_file_t *file);

// Type
char find_sym_type64(Elf64_Sym *sym, Elf64_Shdr *shdr);
char find_sym_type32(Elf32_Sym *sym, Elf32_Shdr *shdr);

// Symbols
void save_elf_symbols64(
    elf_file_t *file, sym_list_t **list, size_t *list_size);
void save_elf_symbols32(
    elf_file_t *file, sym_list_t **list, size_t *list_size);

void sort_symbols(sym_list_t **list, size_t list_size);
void display_symbols64(sym_list_t *list);
void display_symbols32(sym_list_t *list);

#endif /* !NM_H_ */

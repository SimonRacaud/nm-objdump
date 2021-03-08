/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <ar.h>
#include <elf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_list_t.h"

#define EXIT_ERROR               84
#define ERROR_PTR                (void *) -1
#define E_INDENT_IS(h, key, val) (h->e_ident[key] == val)

typedef struct elf_file_s {
    char *filename;
    int fd;
    void *content;
    size_t size;
    Elf64_Ehdr *elf_head64;
    Elf32_Ehdr *elf_head32;
    Elf64_Shdr *sections64;
    Elf32_Shdr *sections32;
    Elf64_Shdr *sym_head64;
    Elf32_Shdr *sym_head32;
    char *strtab_sect;

} elf_file_t;

int my_nm(const char *filename, int argc);

int load_elf_header(elf_file_t *file);

// load file
int load_file(const char *filename, elf_file_t *file);
void close_file(elf_file_t *file);

// nm archi
int nm64(elf_file_t *file);
int nm32(elf_file_t *file);

// section
Elf32_Shdr *get_sym_sect_hdr32(elf_file_t *file);
Elf64_Shdr *get_sym_sect_hdr64(elf_file_t *file);
char *get_strtab_sect32(elf_file_t *file);
char *get_strtab_sect64(elf_file_t *file);
Elf32_Shdr *get_section_header32(Elf32_Ehdr *head);
Elf64_Shdr *get_section_header64(Elf64_Ehdr *head);

Elf64_Sym *symbol64_generator(Elf64_Shdr *sym_section, void *content);
Elf32_Sym *symbol32_generator(Elf32_Shdr *sym_section, void *content);

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

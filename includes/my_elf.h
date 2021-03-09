/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** my_elf
*/

#ifndef MY_ELF_H_
#define MY_ELF_H_

#include <elf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define EXIT_ERROR               84
#define ERROR_PTR                (void *) -1
#define E_INDENT_IS(h, key, val) (h->e_ident[key] == val)

typedef struct elf_file_s {
    char *filename;
    char *app_name;
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

// elf archive
int archive(elf_file_t *file);

// loading
int load_elf_header(elf_file_t *file);

// load file
int load_file(const char *filename, elf_file_t *file, const char *app_name);
void close_file(elf_file_t *file);

// elf section
Elf32_Shdr *get_section_header32(Elf32_Ehdr *head);
Elf64_Shdr *get_section_header64(Elf64_Ehdr *head);

// tools
char **my_str_to_word_array(const char *str, const char *delim);
int str_to_number(const char *buff, size_t len);

#endif /* !MY_ELF_H_ */

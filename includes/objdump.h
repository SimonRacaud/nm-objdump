/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_elf.h"

int my_objdump(const char *filename);

#define FILE_FORMAT64 "elf64-x86-64"
#define FILE_FORMAT32 "elf32-i386"

typedef struct elf_map {
    Elf64_Half value;
    const char *label;
} elf_map_t;

// file header description
int show_file_header32(elf_file_t *file);
int show_file_header64(elf_file_t *file);

// objdump
int my_objdump(const char *filename);
int objdump_run(elf_file_t *file);

int objdump64(elf_file_t *file);
int objdump32(elf_file_t *file);

// show sections
int show_sections64(elf_file_t *file);
int show_sections32(elf_file_t *file);
int print_section_content(
    Elf64_Addr addr, Elf64_Off offset, void *content, size_t size);

#endif /* !OBJDUMP_H_ */

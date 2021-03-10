/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive
*/

#ifndef ARCHIVE_H_
#define ARCHIVE_H_

#include <ar.h>
#include "my_elf.h"

typedef struct ar_hdr ar_header_t;

typedef struct elf_archive {
    ar_header_t *header;
    char *content;
    int size;
} archive_t;

#define ARCH_SYM_TAB_BEG "//"
#define GET_NEXT_SECTION(file) \
    archive_section_generator((char *) file->content + SARMAG, file->size);

void clear_elf_file(elf_file_t *file);
int load_elf_from_buffer(char *filename, archive_t *section, elf_file_t *file);

archive_t *archive_section_generator(char *content, size_t max_size);

void launch_elf_app(int *status, elf_file_t *file);

#endif /* !ARCHIVE_H_ */

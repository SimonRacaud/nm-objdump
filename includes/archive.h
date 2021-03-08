/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive
*/

#ifndef ARCHIVE_H_
#define ARCHIVE_H_

#include <ar.h>
#include "nm.h"

typedef struct ar_hdr ar_header_t;

typedef struct elf_archive {
    ar_header_t *header;
    char *content;
    int size;
} archive_t;

#define ARCH_SYM_TAB_BEG "//"

// #define  ARFMAG   "`\n"         /* header trailer string */
// struct  ar_hdr                  /* file member header */
// {
//     char    ar_name[16];        /* '/' terminated file member name */
//     char    ar_date[12];        /* file member date */
//     char    ar_uid[6]           /* file member user identification */
//     char    ar_gid[6]           /* file member group identification */
//     char    ar_mode[8]          /* file member mode (octal) */
//     char    ar_size[10];        /* file member size */
//     char    ar_fmag[2];         /* header trailer string */
// };

void clear_elf_file(elf_file_t *file);
int load_elf_from_buffer(char *filename, archive_t *section, elf_file_t *file);

archive_t *archive_section_generator(char *content, size_t max_size);

#endif /* !ARCHIVE_H_ */

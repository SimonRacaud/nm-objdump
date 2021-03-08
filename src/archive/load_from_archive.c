/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** load_from_archive
*/

#include "archive.h"

char *str_slash_dup(char *str)
{
    size_t size = 0;

    while (str[size] != '/')
        size++;
    return strndup(str, size);
}

int load_elf_from_buffer(char *filename, archive_t *section, elf_file_t *file)
{
    file->filename = str_slash_dup(filename);
    file->content = (char *) section->header + sizeof(ar_header_t);
    file->size = section->size;
    return EXIT_SUCCESS;
}

void clear_elf_file(elf_file_t *file)
{
    free(file->filename);
}
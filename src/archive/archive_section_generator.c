/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive_section_generator
*/

#include "archive.h"

archive_t *archive_section_generator(char *content, size_t max_size)
{
    static char *content_ptr = NULL;
    archive_t *section;

    if (!content_ptr)
        content_ptr = content;
    if ((content_ptr - content) + sizeof(ar_header_t) > max_size)
        return NULL;
    section = malloc(sizeof(archive_t));
    if (!section)
        return NULL;
    section->header = (ar_header_t *) content_ptr;
    section->size = str_to_number(section->header->ar_size, 10);
    if ((content_ptr - content) + sizeof(ar_header_t) + section->size
        > max_size) {
        fprintf(stderr, "nm: truncated archive\n");
        return NULL;
    }
    section->content = content_ptr + sizeof(ar_header_t);
    content_ptr += sizeof(ar_header_t) + section->size;
    return section;
}
/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** print_section_content
*/

#include "objdump.h"

const size_t LINE_LENGTH = 16;
const size_t LINE_HEX_SPLIT = 4;

static void print_octet(char *addr, size_t offset, size_t max)
{
    if (offset >= max) {
        printf("  ");
    } else {
        printf("%02x", (unsigned int) addr[offset] & 255);
    }
}

static void print_char(char *addr, size_t offset, size_t max)
{
    char c;

    if (offset >= max) {
        printf(" ");
    } else {
        c = addr[offset];
        if (c < 32 || c > 126) {
            printf(".");
        } else {
            printf("%c", c);
        }
    }
}

void print_line(char *addr, size_t max_size, size_t *current_size)
{
    printf(" %04x ", (unsigned int) *current_size);
    for (size_t i = 0; i < LINE_LENGTH; i++) {
        if (i % LINE_HEX_SPLIT == 0 && i) {
            printf(" ");
        }
        print_octet(addr, *current_size + i, max_size);
    }
    printf("  ");
    for (size_t i = 0; i < LINE_LENGTH; i++, (*current_size)++) {
        print_char(addr, *current_size, max_size);
    }
    printf("\n");
}

int print_section_content(Elf64_Off offset, size_t size, void *content)
{
    char *area = (char *) content + offset;
    size_t current_size = 0;

    while (current_size < size) {
        print_line(area, size, &current_size);
    }
    return EXIT_SUCCESS;
}
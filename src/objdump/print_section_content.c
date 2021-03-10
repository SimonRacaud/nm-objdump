/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** print_section_content
*/

#include "objdump.h"

const size_t LINE_LENGTH = 0x10;
const size_t LINE_HEX_SPLIT = 4;

static void print_octet(char *addr, Elf64_Off offset, Elf64_Off max)
{
    if (offset >= max) {
        printf("  ");
    } else {
        printf("%02x", (unsigned int) addr[offset] & 255);
    }
}

static void print_char(char *addr, Elf64_Off offset, Elf64_Off max)
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

static void print_line(
    Elf64_Addr addr, char *content, Elf64_Off max_size, Elf64_Off *offset)
{
    printf(" %04x ", (unsigned int) addr);
    for (size_t i = 0; i < LINE_LENGTH; i++) {
        if (i % LINE_HEX_SPLIT == 0 && i) {
            printf(" ");
        }
        print_octet(content, (*offset + i), max_size);
    }
    printf("  ");
    for (size_t i = 0; i < LINE_LENGTH; i++, (*offset)++) {
        print_char(content, *offset, max_size);
    }
    printf("\n");
}

int print_section_content(
    Elf64_Addr addr, Elf64_Off offset, void *content, size_t size)
{
    char *content_addr = content;
    size_t max_size = size + offset;

    while (offset < max_size) {
        print_line(addr, content_addr, max_size, &offset);
        addr += LINE_LENGTH;
    }
    return EXIT_SUCCESS;
}
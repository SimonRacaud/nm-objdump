/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** objdumArchi
*/

#include "objdump.h"

int objdump64(elf_file_t *file)
{
    show_file_header64(file);
    show_sections64(file);
    return EXIT_SUCCESS;
}

int objdump32(elf_file_t *file)
{
    show_file_header32(file);
    show_sections32(file);
    return EXIT_SUCCESS;
}
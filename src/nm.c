/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** nm
*/

#include "nm.h"

int my_nm(const char *filename)
{
    elf_file_t file;

    if (load_file(filename, &file) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (load_elf_header(&file) != EXIT_SUCCESS) {
        close_file(&file);
        return EXIT_ERROR;
    }
    if (file.elf_head->e_ident[EI_CLASS] == ELFCLASS32) {
    } else if (file.elf_head->e_ident[EI_CLASS] == ELFCLASS64) {
        if (nm64(&file) != EXIT_SUCCESS) {
            close_file(&file);
            return EXIT_ERROR;
        }
    }
    close_file(&file);
    return EXIT_SUCCESS;
}
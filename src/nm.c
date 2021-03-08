/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** nm
*/

#include "nm.h"

static int error_exit(elf_file_t *file)
{
    close_file(file);
    return EXIT_ERROR;
}

static void show_prelude(const char *filename, int argc)
{
    if (argc > 2)
        printf("\n");
    if (argc > 2)
        printf("%s:\n", filename);
}

int my_nm(const char *filename, int argc)
{
    elf_file_t file;

    if (load_file(filename, &file) != EXIT_SUCCESS)
        return EXIT_ERROR;
    if (load_elf_header(&file) != EXIT_SUCCESS) {
        return error_exit(&file);
    }
    show_prelude(filename, argc);
    if (file.elf_head64->e_ident[EI_CLASS] == ELFCLASS32) {
        if (nm32(&file) != EXIT_SUCCESS) {
            return error_exit(&file);
        }
    } else if (file.elf_head64->e_ident[EI_CLASS] == ELFCLASS64) {
        if (nm64(&file) != EXIT_SUCCESS) {
            return error_exit(&file);
        }
    }
    close_file(&file);
    return EXIT_SUCCESS;
}
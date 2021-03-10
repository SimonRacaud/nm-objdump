/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** objdump
*/

#include "objdump.h"

int objdump_run(elf_file_t *file)
{
    if (load_elf_header(file) != EXIT_SUCCESS) {
        close_file(file);
        return EXIT_ERROR;
    }
    if (file->elf_head64->e_ident[EI_CLASS] == ELFCLASS32) {
        if (objdump32(file) != EXIT_SUCCESS) {
            close_file(file);
            return EXIT_ERROR;
        }
    } else if (file->elf_head64->e_ident[EI_CLASS] == ELFCLASS64) {
        if (objdump64(file) != EXIT_SUCCESS) {
            close_file(file);
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

int my_objdump(const char *filename)
{
    elf_file_t file;
    int archive_status;

    if (load_file(filename, &file, "objdump") != EXIT_SUCCESS)
        return EXIT_ERROR;
    archive_status = archive(&file);
    if (archive_status != EXIT_FAILURE) {
        close_file(&file);
        return archive_status;
    }
    if (objdump_run(&file) != EXIT_SUCCESS)
        return EXIT_ERROR;
    close_file(&file);
    return EXIT_SUCCESS;
}
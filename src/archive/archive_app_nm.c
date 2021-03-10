/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive_app_nm
*/

#include "archive.h"
#include "nm.h"

void launch_elf_app(int *status, elf_file_t *file)
{
    printf("\n%s:\n", file->filename);
    *status = nm_show_content(file, 1);
}
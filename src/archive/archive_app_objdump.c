/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive_app_nm
*/

#include "archive.h"
#include "objdump.h"

void launch_elf_app(int *status, elf_file_t *file)
{
    *status = objdump_run(file);
}
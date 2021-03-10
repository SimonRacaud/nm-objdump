/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** liste des en-têtes des sections
*/

#include "nm.h"

Elf32_Shdr *get_section_header32(Elf32_Ehdr *head)
{
    if (!head || head->e_shoff == 0) {
        return NULL;
    }
    return (Elf32_Shdr *) ((char *) head + head->e_shoff);
}

Elf64_Shdr *get_section_header64(Elf64_Ehdr *head)
{
    if (!head || head->e_shoff == 0) {
        return NULL;
    }
    return (Elf64_Shdr *) ((char *) head + head->e_shoff);
}
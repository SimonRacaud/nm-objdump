/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** liste des en-têtes des sections
*/

#include "nm.h"

// typedef struct {
//     uint32_t   sh_name;      // section name position
//     uint32_t   sh_type;
//     uint64_t   sh_flags;
//     Elf64_Addr sh_addr;
//     Elf64_Off  sh_offset;    // elf_sym_t => section position
//     uint64_t   sh_size;      // size of the section
//     uint32_t   sh_link;
//     uint32_t   sh_info;
//     uint64_t   sh_addralign;
//     uint64_t   sh_entsize;   // size of a ElfX_sym
// } Elf64_Shdr;

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
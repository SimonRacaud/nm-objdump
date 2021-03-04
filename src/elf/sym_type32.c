/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** sym_type
*/

#include "nm.h"

static char find_flags_charlie(Elf32_Sym *symbol, Elf32_Shdr *sections)
{
    if (sections[symbol->st_shndx].sh_type == SHT_PROGBITS
        && (sections[symbol->st_shndx].sh_flags == SHF_ALLOC
            || sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_MERGE)))
        return 'R';
    if (sections[symbol->st_shndx].sh_type == SHT_NOBITS
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if ((sections[symbol->st_shndx].sh_type == SHT_FINI_ARRAY
            || sections[symbol->st_shndx].sh_type == SHT_INIT_ARRAY)
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'T';
    return '?';
}

static char find_flags_beta(Elf32_Sym *symbol, Elf32_Shdr *sections)
{
    if (sections[symbol->st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    if (sections[symbol->st_shndx].sh_type == SHT_PROGBITS
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'D';
    if (sections[symbol->st_shndx].sh_type == SHT_PROGBITS
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 'T';
    if (symbol->st_shndx == SHN_UNDEF)
        return 'U';
    if (symbol->st_shndx == SHN_ABS)
        return 'A';
    if (symbol->st_shndx == SHN_COMMON)
        return 'C';
    return find_flags_charlie(symbol, sections);
}

static char find_flags_alpha(Elf32_Sym *symbol, Elf32_Shdr *sections)
{
    if (ELF32_ST_BIND(symbol->st_info) == STB_WEAK) {
        return (symbol->st_shndx == SHN_UNDEF) ? 'w' : 'W';
    }
    if (ELF32_ST_BIND(symbol->st_info) == STB_GNU_UNIQUE) {
        return 'u';
    }
    if (ELF32_ST_BIND(symbol->st_info) == STB_WEAK
        && ELF32_ST_TYPE(symbol->st_info) == STT_OBJECT) {
        return (symbol->st_shndx == SHN_UNDEF) ? 'v' : 'V';
    }
    return find_flags_beta(symbol, sections);
}

char find_sym_type32(Elf32_Sym *symbol, Elf32_Shdr *sections)
{
    char type = '\0';

    type = find_flags_alpha(symbol, sections);
    if (ELF32_ST_BIND(symbol->st_info) == STB_LOCAL && type != '?') {
        type += 32;
    }
    return type;
}

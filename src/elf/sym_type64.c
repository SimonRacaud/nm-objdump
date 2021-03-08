/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** sym_type
*/

#include "nm.h"

static char find_type_sub1(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    if (sym->st_shndx == SHN_UNDEF)
        return 'U';
    else if (sym->st_shndx == SHN_ABS)
        return 'A';
    if (sym->st_shndx == SHN_COMMON)
        return 'C';
    else if (shdr[sym->st_shndx].sh_type == SHT_NOBITS
        && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    return 0;
}

static char find_type_sub2(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym->st_shndx].sh_flags == SHF_ALLOC)
        return 'R';
    if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'D';
    else if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 'T';
    if (shdr[sym->st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    return 0;
}

static char find_type_bind(Elf64_Sym *sym)
{
    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
        return 'u';
    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
        return (sym->st_shndx == SHN_UNDEF) ? 'w' : 'W';
    }
    if (ELF64_ST_BIND(sym->st_info) == STB_WEAK
        && ELF64_ST_TYPE(sym->st_info) == STT_OBJECT) {
        return (sym->st_shndx == SHN_UNDEF) ? 'v' : 'V';
    }
    return 0;
}

char find_sym_type64(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    char c;
    char ret;

    ret = find_type_bind(sym);
    c = find_type_sub1(sym, shdr);
    if (c != 0)
        ret = c;
    c = find_type_sub2(sym, shdr);
    if (c != 0)
        ret = c;
    if (ret == 0)
        ret = '?';
    if (ELF64_ST_BIND(sym->st_info) == STB_LOCAL && ret != '?')
        ret += 32;
    return ret;
}

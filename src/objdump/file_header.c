/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** file header
*/

#include "objdump.h"

static const elf_map_t MACHINES[] = {{EM_NONE, "None"}, {EM_M32, "WE32100"},
    {EM_SPARC, "Sparc"}, {EM_386, "i386"}, {EM_68K, "MC68000"},
    {EM_88K, "MC88000"}, {EM_860, "Intel 80860"}, {EM_MIPS, "MIPS R3000"},
    {EM_PARISC, "HPPA"}, {EM_SPARC32PLUS, "Sparc v8+"}, {EM_PPC, "PowerPC"},
    {EM_PPC64, "PowerPC64"}, {EM_S390, "IBM S/390"}, {EM_ARM, "ARM"},
    {EM_SH, "Renesas / SuperH SH"}, {EM_SPARCV9, "Sparc v9"},
    {EM_IA_64, "Intel IA-64"}, {EM_X86_64, "i386:x86-64"}, {-1, NULL}};

static const char *get_archi(Elf64_Half value)
{
    for (size_t i = 0; MACHINES[i].label != NULL; i++) {
        if (MACHINES[i].value == value) {
            return MACHINES[i].label;
        }
    }
    return "undefined";
}

static int get_flag_value(Elf64_Half value)
{
    if (value == ET_REL)
        return (HAS_SYMS | HAS_RELOC);
    if (value == ET_EXEC)
        return (D_PAGED | HAS_SYMS | EXEC_P);
    if (value == ET_DYN)
        return (D_PAGED | DYNAMIC | HAS_SYMS);
    return 0;
}

static void show_flags_labels(Elf64_Half value)
{
    if (value == ET_REL)
        printf("HAS_RELOC, HAS_SYMS");
    if (value == ET_EXEC)
        printf("EXEC_P, HAS_SYMS, D_PAGED");
    if (value == ET_DYN)
        printf("HAS_SYMS | DYNAMIC | D_PAGED");
    printf("\n");
}

int show_file_header64(elf_file_t *file)
{
    printf("%s:\tfile format ", file->filename);
    printf("%s\n", FILE_FORMAT64);
    printf("architecture: %s, flags 0x%08x:\n",
        get_archi(file->elf_head64->e_machine),
        get_flag_value(file->elf_head64->e_type));
    show_flags_labels(file->elf_head64->e_type);
    printf("start address 0x%016lx\n\n", file->elf_head64->e_entry);
    return EXIT_SUCCESS;
}

int show_file_header32(elf_file_t *file)
{
    printf("%s:\tfile format ", file->filename);
    printf("%s\n", FILE_FORMAT32);
    printf("architecture: %s, flags 0x%08x:\n",
        get_archi(file->elf_head32->e_machine),
        get_flag_value(file->elf_head32->e_type));
    show_flags_labels(file->elf_head32->e_type);
    printf("start address 0x%016x\n\n", file->elf_head32->e_entry);
    return EXIT_SUCCESS;
}
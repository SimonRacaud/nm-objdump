/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** archive
*/

#include "archive.h"

static bool is_valid_archive(elf_file_t *file)
{
    if (strncmp((char *) file->content, ARMAG, SARMAG) != 0) {
        return 0;
    }
    return 1;
}

static char *get_section_name(archive_t *section, archive_t *strtab)
{
    char *name = NULL;
    size_t name_idx;

    if (!section)
        return NULL;
    if (section->header->ar_name[0] == '/') {
        if (!strtab || !strtab->content)
            return NULL;
        name_idx = str_to_number(section->header->ar_name + 1, 15);
        name = &strtab->content[name_idx];
    } else {
        name = section->header->ar_name;
    }
    return name;
}

static int read_sections(
    archive_t *section, archive_t *strtab, elf_file_t *file)
{
    char *filename = get_section_name(section, strtab);
    elf_file_t elf;
    int status = EXIT_SUCCESS;

    if (!filename || !section)
        return EXIT_ERROR;
    if (load_elf_from_buffer(filename, section, &elf) != EXIT_SUCCESS)
        return EXIT_ERROR;
    printf("\n%s:\n", elf.filename);
    status = nm_show_content(&elf, 1);
    clear_elf_file(&elf);
    free(section);
    section =
        archive_section_generator((char *) file->content + SARMAG, file->size);
    if (section) {
        return read_sections(section, strtab, file);
    }
    return status;
}

int archive(elf_file_t *file)
{
    archive_t *section;
    archive_t *strtab = NULL;
    int ret;

    if (is_valid_archive(file) == false)
        return EXIT_FAILURE;
    section =
        archive_section_generator((char *) file->content + SARMAG, file->size);
    if (!section)
        return EXIT_ERROR;
    free(section);
    section =
        archive_section_generator((char *) file->content + SARMAG, file->size);
    if (strncmp(section->header->ar_name, ARCH_SYM_TAB_BEG, 2) == 0) {
        strtab = section;
        section = archive_section_generator(
            (char *) file->content + SARMAG, file->size);
    }
    ret = read_sections(section, strtab, file);
    free(strtab);
    return ret;
}
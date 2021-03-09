/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** load_file
*/

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "nm.h"

static int open_error_manager(const char *filename, const char *app_name)
{
    fprintf(stderr, "%s: '%s': ", app_name, filename);
    if (errno == EACCES)
        fprintf(stderr, "Permission denied");
    else if (errno == ENOENT)
        fprintf(stderr, "No such file");
    fprintf(stderr, "\n");
    return EXIT_ERROR;
}

static int open_file(const char *filename, elf_file_t *file,
    const char *app_name, struct stat *st)
{
    file->fd = open(filename, O_RDONLY);
    if (file->fd == -1)
        return open_error_manager(filename, app_name);
    fstat(file->fd, st);
    if (S_ISDIR(st->st_mode) == true) {
        fprintf(
            stderr, "%s: Warning: '%s' is a directory\n", app_name, filename);
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int load_file(const char *filename, elf_file_t *file, const char *app_name)
{
    struct stat st;

    if (open_file(filename, file, app_name, &st) != EXIT_SUCCESS)
        return EXIT_ERROR;
    file->size = st.st_size;
    file->content =
        mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, file->fd, 0);
    if (file->content == ERROR_PTR) {
        close(file->fd);
        return EXIT_ERROR;
    }
    file->app_name = strdup(app_name);
    file->filename = strdup(filename);
    return EXIT_SUCCESS;
}

void close_file(elf_file_t *file)
{
    free(file->filename);
    free(file->app_name);
    close(file->fd);
}
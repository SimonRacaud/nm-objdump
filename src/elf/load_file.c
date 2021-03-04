/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** load_file
*/

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "nm.h"

static void open_error_manager(const char *filename)
{
    fprintf(stderr, "nm: '%s': ", filename);
    if (errno == EACCES)
        fprintf(stderr, "permission denied");
    else
        fprintf(stderr, "file open error");
    fprintf(stderr, "\n");
}

int load_file(const char *filename, elf_file_t *file)
{
    struct stat s;

    file->fd = open(filename, O_RDONLY);
    if (file->fd == -1) {
        open_error_manager(filename);
        return EXIT_ERROR;
    }
    fstat(file->fd, &s);
    file->size = s.st_size;
    file->content = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, file->fd, 0);
    if (file->content == ERROR_PTR) {
        close(file->fd);
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

void close_file(elf_file_t *file)
{
    close(file->fd);
}
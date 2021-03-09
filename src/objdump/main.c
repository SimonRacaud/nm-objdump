/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** main
*/

#include "objdump.h"

const char *DEFAULT_FILENAME = "a.out";

static int usage(int status, const char *filename)
{
    printf("%s <file-1> <file-n>\n", filename);
    return status;
}

int main(int argc, char **argv)
{
    int status = EXIT_SUCCESS;
    int ret;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0)
            return usage(EXIT_SUCCESS, argv[0]);
    }
    if (argc == 1) {
        return my_objdump(DEFAULT_FILENAME);
    }
    for (int i = 1; i < argc; i++) {
        ret = my_objdump(argv[i]);
        if (ret != EXIT_SUCCESS)
            status = ret;
    }
    return status;
}

/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** main
*/

#include "nm.h"

const char *DEFAULT_FILENAME = "./a.out";

static int usage(int exit, char *filename)
{
    printf("usage: %s <obj-file1> <?obj-file2>\n", filename);
    return exit;
}

int main(int argc, char **argv)
{
    int ret;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            return usage(EXIT_SUCCESS, argv[0]);
        }
    }
    if (argc == 1) {
        return my_nm(DEFAULT_FILENAME);
    }
    for (int i = 1; i < argc; i++) {
        if (argc > 3)
            printf("\n");
        if (argc > 2)
            printf("%s:\n", argv[i]);
        ret = my_nm(argv[i]);
        if (ret != EXIT_SUCCESS)
            return ret;
    }
    return EXIT_SUCCESS;
}

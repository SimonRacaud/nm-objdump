/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** sort_symbols
*/

#include <locale.h>
#include "nm.h"

void sort_symbols(sym_list_t **list, size_t list_size)
{
    if (!setlocale(LC_ALL, "en_US")) {
        fprintf(stderr, "setlocal error\n");
    }
    sort_list(list, list_size, &strcoll);
}

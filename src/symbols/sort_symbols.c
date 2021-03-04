/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** sort_symbols
*/

#include <locale.h>
#include "nm.h"

void sort_symbols(sym_list_t **list)
{
    setlocale(LC_ALL, "");
    my_sort_list(list, &strcoll);
}

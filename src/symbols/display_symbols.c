/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** display_symbols
*/

#include "nm.h"

void display_symbols64(sym_list_t *list)
{
    for (sym_list_t *ptr = list; ptr != NULL; ptr = ptr->next) {
        if (ptr->type != 'U' && ptr->type != 'w') {
            printf("%016lx ", ptr->value);
        } else {
            printf("                 ");
        }
        printf("%c %s\n", ptr->type, ptr->name);
    }
}

void display_symbols32(sym_list_t *list)
{
    for (sym_list_t *ptr = list; ptr != NULL; ptr = ptr->next) {
        if (ptr->type != 'U' && ptr->type != 'w') {
            printf("%08lx ", ptr->value);
        } else {
            printf("         ");
        }
        printf("%c %s\n", ptr->type, ptr->name);
    }
}
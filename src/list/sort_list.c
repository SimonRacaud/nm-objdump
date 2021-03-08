/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** sort_list
*/

#include "nm.h"

static void tab_filler(sym_list_t *list, sym_list_t **tab)
{
    sym_list_t *move = list;

    for (size_t i = 0; move; move = move->next, i++) {
        tab[i] = move;
        tab[i + 1] = NULL;
    }
}

static void move_it(sym_list_t **list, sym_list_t **tab)
{
    sym_list_t *move = *list;

    for (ssize_t i = 0; tab[i + 1]; i++) {
        move = tab[i];
        tab[i]->next = tab[i + 1];
        tab[i + 1]->next = NULL;
        move = move->next;
    }
    *list = tab[0];
}

bool sort_list(sym_list_t **list, size_t size, int (*cmp)())
{
    sym_list_t *tmp;
    sym_list_t **tab;

    if (size == 1)
        return true;
    tab = malloc(sizeof(sym_list_t *) * (size + 1));
    if (!tab)
        return false;
    tab_filler(*list, tab);
    for (size_t i = 0; tab[i + 1]; i++) {
        if (cmp(tab[i]->name, tab[i + 1]->name) > 0) {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = -1;
        }
    }
    move_it(list, tab);
    free(tab);
    return true;
}
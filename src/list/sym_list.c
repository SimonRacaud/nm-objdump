/*
** EPITECH PROJECT, 2020
** LIBMY
** File description:
** Created: 2020-04-01T09:26:57+02:00 | Author: simon
*/

#include "nm.h"

static sym_list_t *list_sym_create_node(
    char *name, Elf64_Addr value, char type)
{
    sym_list_t *node = NULL;

    node = malloc(sizeof(sym_list_t));
    if (!node)
        return NULL;
    node->next = NULL;
    node->name = strdup(name);
    node->value = value;
    node->type = type;
    return node;
}

int sym_list_add(sym_list_t **list, char *name, Elf64_Addr value, char type)
{
    sym_list_t *ptr = *list;

    if (!(*list)) {
        (*list) = list_sym_create_node(name, value, type);
        if (!(*list))
            return EXIT_ERROR;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = list_sym_create_node(name, value, type);
        if (!ptr->next) {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

void sym_list_destroy(sym_list_t *list)
{
    sym_list_t *next_ptr = NULL;
    sym_list_t *ptr = list;

    if (!list) {
        return;
    } else {
        do {
            next_ptr = ptr->next;
            free(ptr->name);
            free(ptr);
            ptr = next_ptr;
        } while (next_ptr);
    }
}

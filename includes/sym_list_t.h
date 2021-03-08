/*
** EPITECH PROJECT, 2020
** LIBMY
** File description:
** Created: 2020-04-01T09:27:36+02:00 | Author: simon
*/

#ifndef H_SYM_LIST
#define H_SYM_LIST

typedef struct linked_list_sym {
    struct linked_list_sym *next;
    char *name;
    Elf64_Addr value;
    char type;
    uint16_t st_shndx;
} sym_list_t;

int sym_list_add(sym_list_t **list, char *name, Elf64_Addr value, char type);
void sym_list_destroy(sym_list_t *list);

bool sort_list(sym_list_t **list, size_t size, int (*cmp)());

#endif

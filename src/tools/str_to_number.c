/*
** EPITECH PROJECT, 2021
** B-PSU-400-REN-4-1-nmobjdump-simon.racaud
** File description:
** str_to_number
*/

#include <stdlib.h>
#include <string.h>

int str_to_number(const char *buff, size_t len)
{
    char *size_str = strndup(buff, len);
    int ret;

    if (!size_str)
        return 0;
    for (size_t i = 0; size_str[i] != '\0'; i++) {
        if (size_str[i] == ' ') {
            size_str[i] = '\0';
            break;
        }
    }
    ret = atoi(size_str);
    free(size_str);
    return ret;
}
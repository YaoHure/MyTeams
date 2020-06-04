/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** my_itoa
*/

#include "../include/my.h"

char *my_intostr(int nb)
{
    char *str = NULL;
    int len = 0;

    for (int tmp = nb; tmp > 0; tmp = tmp / 10, len++);
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb = nb / 10;
    }
    return (str);
}
/*
** EPITECH PROJECT, 2020
** my_teams_bdd
** File description:
** my_bdd
*/

#include "my.h"

int my_check_arguments(char *str)
{
    int ret = 0;
    int len = 0;

    if (!str)
        return (0);

    len = strlen(str) - 1;
    if (str[0] == '"')
        ret++;
    len = (str[len] == '\n') ? len - 1 : len;
    if (str[len] == '"')
        ret++;
    return (ret);
}

char *my_skip_char(char *str, char c)
{
    char *dest = NULL;
    int j = 0;

    if (!str)
        return (NULL);
    dest = malloc(sizeof(char) * (strlen(str) - 1));
    for (int i = 0; str[i]; i++) {
        if (str[i] != c) {
            dest[j] = str[i];
            j++;
        }
    }
    dest[j] = '\0';
    return (dest);
}

/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my_strndup.c
*/

#include "../include/my.h"

char **my_dup_array(char **array)
{
    int i = 0;
    char **dest_array = malloc(sizeof(char *) * (my_len_array(array) + 1));

    for (i = 0; array[i]; i++)
        dest_array[i] = strdup(array[i]);
    dest_array[i] = NULL;
    return (dest_array);
}

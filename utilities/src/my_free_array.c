/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_len_array
*/

#include "../include/my.h"

char **my_free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return (array);
}

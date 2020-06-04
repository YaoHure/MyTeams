/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_len_array
*/

#include "../include/my.h"

void my_printf_to_file(FILE *fp, char **array)
{
    for (int i = 0; array[i]; i++)
        fprintf(fp, "%s", array[i]);
}

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_len_array
*/

#include "../include/my.h"

int my_len_array(char **array)
{
    int len = 0;
    for (; array[len]; len++);
    return (len);
}

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (0);
    }
    return (1);
}
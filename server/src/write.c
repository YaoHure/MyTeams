/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** write
*/

#include "../include/server.h"

char *delete_n(char *line)
{
    char *new_line = malloc(sizeof(strlen(line)));
    int i = 0;

    if (!new_line)
        return (NULL);
    for (; line[i] != '\n' && line[i] != '\0'; i++)
        new_line[i] = line[i];
    new_line[i] = '\0';
    return (new_line);
}
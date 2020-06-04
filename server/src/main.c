/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include "../include/server.h"

int main(int ac, char **av)
{
    if (arg_check(ac, av) == 84)
        return (84);
    else if (create_server(av) == 84)
        return (84);
    return (0);
}
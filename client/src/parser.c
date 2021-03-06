/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser
*/

#include "../include/client.h"

int is_number(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
    }
    return (0);
}

int check_ac(int ac)
{
    if (ac < 3) {
        printf("USAGE:\t./myteams_server port\n\n");
        printf("\tport\tis the port number on which the server socket");
        printf(" listens.\n");
        return (84);
    }
    return (0);
}

int arg_check(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        printf("USAGE:\t./myteams_cli ip port\n\n");
        printf("\tip\tis the server ip address on which the server ");
        printf("socket listens\n");
        printf("\tport\tis the port number on which the server socket");
        printf(" listens.\n");
        return (0);
    } else if (ac == 3 && is_number(av[2]) == 84) {
        printf("Enter a valid port.\n");
        return (84);
    }
    return (check_ac(ac));
}
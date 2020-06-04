/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** print_create
*/

#include "my_functions.h"
#include "logging_client.h"

void print_created_teams(__attribute__((unused))t_cli *cli, char **argv)
{
    if (argv && argv[1] && argv[2] && argv[3]) {
        client_print_team_created(argv[1], argv[2], argv[3]);
    }
}

void print_created_channel(__attribute__((unused))t_cli *cli, char **argv)
{
    if (argv && argv[1] && argv[2] && argv[3]) {
        client_print_channel_created(argv[1], argv[2], argv[3]);
    }
}

void print_created_threads(__attribute__((unused))t_cli *cli, char **argv)
{
    if (argv && argv[1] && argv[2] && argv[3]) {
        client_print_channel_created(argv[1], argv[2], argv[3]);
    }
}

void print_created_reply(__attribute__((unused))t_cli *cli, char **argv)
{
    if (argv && argv[1] && argv[2] && argv[3]) {
        client_print_channel_created(argv[1], argv[2], argv[3]);
    }
}
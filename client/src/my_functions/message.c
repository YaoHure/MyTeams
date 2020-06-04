/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** message
*/

#include "my_functions.h"
#include "logging_client.h"
#include "logging_server.h"

void msg_received(__attribute__((unused))t_cli *cli, char **argv)
{
    if (argv && argv[1] != NULL && argv[2] != NULL) {
        client_event_private_message_received(argv[1], argv[2]);
    }
}
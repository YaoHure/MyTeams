/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** inetinfo
*/

#include "../include/server.h"

void con_type(struct sockaddr_in *addr, int port)
{
    addr->sin_addr.s_addr = htonl(INADDR_ANY);
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
}

int bind_listen(int sock, struct sockaddr_in addr)
{
    if (bind(sock, (struct sockaddr *)(&addr), sizeof(addr)) == -1) {
        perror("Binding error : ");
        return (84);
    }
    if (listen(sock, 1) == -1) {
        perror("Can't listen : ");
        return (84);
    }
    return (0);
}

int socket_close(t_server *conf)
{
    if (close(conf->ssock) == -1) {
        fprintf(stderr, "Failed to close socket.\n");
        return (84);
    }
    printf("Connection with %s closed.\n", conf->ip);
    return (0);
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** accept
*/

#include "../include/server.h"

int isaccepted(t_server *config, t_client *clients)
{
    struct sockaddr_in csin = { 0 };
    socklen_t sinsize = sizeof(csin);
    config->csock = accept(config->ssock, (struct sockaddr *)&csin, &sinsize);
    if (config->csock == -1) {
        perror("accept()");
        return (84);
    }
    printf("Connection from %s\n", inet_ntoa(csin.sin_addr));
    config->max = config->csock > config->max ? config->csock : config->max;
    FD_SET(config->csock, &config->rdfs);
    t_client clt = { config->csock, inet_ntoa(csin.sin_addr), NULL, NULL, 0};
    clients[config->actual] = clt;
    config->actual++;
    return (0);
}

int select_cond(t_client *clients, t_server *config)
{
    if (FD_ISSET(STDIN_FILENO, &config->rdfs)) {
        return (84);
    } else if (FD_ISSET(config->ssock, &config->rdfs)) {
        printf("Connexion incoming\n");
        if (isaccepted(config, clients) == 84)
            return (84);
    } else {
        if (my_disconnect(config, clients) == 84)
            return (84);
    }
    return (0);
}
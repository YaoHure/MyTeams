/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "../include/client.h"

int init_con(t_cli *cli)
{
    cli->sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sin = { 0 };
    struct hostent *hostinfo;
    int err = 0;

    hostinfo = gethostbyname(cli->ip);
    if (cli->sock == -1) {
        perror("socket()");
        exit(84);
    }
    sin.sin_addr = *(struct in_addr *) hostinfo->h_addr;
    sin.sin_port = htons(cli->port);
    sin.sin_family = AF_INET;
    err = connect(cli->sock, (struct sockaddr *)&sin, sizeof(struct sockaddr));
    if (err == -1) {
        perror("connect()");
        exit(84);
    }
    return (cli->sock);
}

int socket_client(t_cli *cli)
{
    cli->sock = init_con(cli);
    while (cli->isLogin != 2) {
        FD_ZERO(&cli->wrfs);
        FD_SET(STDIN_FILENO, &cli->wrfs);
        FD_SET(cli->sock, &cli->wrfs);
        if (select(cli->sock + 1, &cli->wrfs, NULL, NULL, NULL) == -1) {
            perror("select()");
            return (84);
        }
        if (select_condition(cli) == 84)
            return (84);
    }
    close(cli->sock);
    return (0);
}

int client_creation(char **av)
{
    t_cli *cli = malloc(sizeof(t_cli));

    if (!cli)
        return (84);
    cli->ip = strdup(av[1]);
    if (!cli->ip)
        return (84);
    cli->port = atoi(av[2]);
    cli->isLogin = 0;
    cli->username = NULL;
    cli->userid = NULL;
    if (socket_client(cli) == 84)
        return (84);
    return (0);
}

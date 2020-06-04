/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "../include/server.h"

int set_fdesc(t_server *config, int i, t_client *clients)
{
    FD_ZERO(&config->rdfs);
    FD_SET(STDIN_FILENO, &config->rdfs);
    FD_SET(config->ssock, &config->rdfs);
    for (i = 0; i < config->actual; i++)
        FD_SET(clients[i].socket, &config->rdfs);
    return (i);
}

int clt_handle(t_server *config)
{
    char *g = NULL;
    size_t size = 0;
    FILE *proto = fdopen(config->csock, "rw");

    if (proto == NULL) {
        dprintf(1, "fdopen failed.\n");
        exit(84);
    }
    if (getline(&g, &size, proto) != -1) {
        printf("line = %s\n", g);
        if (strcmp("exit", g) == 0)
            return (0);
    }
    return (0);
}

int init_connection(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sin = { 0 };

    if (sock == -1)
        exit(84);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("bind()");
        exit(84);
    }
    if (listen(sock, 1) == -1) {
        perror("listen()");
        exit(84);
    }
    return (sock);
}

int socket_creation(t_server *config)
{
    t_client clients[CLIENT_MAX];
    int i = 0;

    config->ssock = init_connection(config->port);
    config->max = config->ssock;
    while (1) {
        i = set_fdesc(config, i, clients);
        if (select(config->max + 1, &config->rdfs, NULL, NULL, NULL) == -1) {
            perror("select()");
            exit(84);
        }
        if (select_cond(clients, config) == 84)
            continue;
    }
    return (0);
}

int create_server(char **av)
{
    t_server *config;

    config = malloc(sizeof(t_server));
    if (!config) {
        dprintf(1, "Error while malloc server structure\n");
        return (84);
    }
    init_struct_bdd(config);
    config->port = atoi(av[1]);
    config->actual = 0;
    if (socket_creation(config) == 84)
        return (84);
    close(config->ssock);
    if (config != NULL)
        free(config);
    return (0);
}

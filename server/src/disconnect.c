/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** disconnect
*/

#include "commands.h"
#include "my.h"
#include "../include/server.h"
#include "logging_client.h"
#include "logging_server.h"

int my_builtins(t_teams *teams, char **array, t_server *srt, t_client *clt)
{
    int i = 0;
    int ret = 0;

    teams->verif = 0;
    for (i = 0; commands_tab[i].name; i++) {
        if ((my_strcmp("/login", array[0]) != 1) && (clt->username == NULL)) {
            dprintf(teams->cfd, "%d\r\n", 55);
            break;
        } else if (my_strcmp(commands_tab[i].name, array[0]) == 1) {
            teams->verif = 1;
            commands_tab[i].fnc(teams, array, srt, clt);
            ret = 1;
            break;
        }
    }
    if (teams->verif == 0)
        dprintf(clt->socket, "500 Command not implemented\n");
    return (ret);
}

int my_clt_handle(int i, t_server *config, t_client *clients, char *line)
{
    char *new_line = NULL;
    t_teams teams;

    if (config->res != 0) {
        if (clients[i].userid != NULL && clients[i].logIn == 0)
            server_event_user_logged_out(clients[i].userid);
        if (close(clients[i].socket) == -1)
            return (84);
        remove_client(clients, i, &config->actual);
    } else {
        new_line = my_clean_str(line);
        teams.cfd = clients[i].socket;
        if (new_line[0] != '\0') {
            char **tab = my_str_to_word_tab(new_line, ' ');
            my_builtins(&teams, tab, config, &clients[i]);
        }
    }
    return (0);
}

int my_disconnect_function(int i, t_server *config, t_client *clients)
{
    FILE *fs = NULL;
    char *clt_line = NULL;
    size_t size = 0;
    t_client *temp = clients;

    if (FD_ISSET(temp[i].socket, &config->rdfs)) {
        fs = fdopen(temp[i].socket, "rw");
        if (getline(&clt_line, &size, fs) == -1)
            config->res = 84;
        if (my_clt_handle(i, config, clients, clt_line) == 84)
            return (84);
    }
    return (0);
}

int my_disconnect(t_server *config, t_client *clients)
{
    int i = 0;

    config->res = 0;
    for (i = 0; i < config->actual; i++) {
        if (my_disconnect_function(i, config, clients) == 84)
            return (84);
    }
    return (0);
}

void remove_client(t_client *clients, int to_remove, int *actual)
{
    void *first = clients + to_remove;
    const void *sec = clients + to_remove + 1;
    size_t third = (*actual - to_remove - 1) * sizeof(t_client);

    memmove(first, sec, third);
    (*actual)--;
}

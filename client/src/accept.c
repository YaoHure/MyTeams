/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** accept
*/

#include "../include/client.h"
#include "my_rfc.h"
#include "my.h"

int my_rfcode(t_cli *cli, char **array)
{
    int i = 0;
    int ret = 0;

    for (i = 0; rfc_tab[i].name; i++) {
        if ((my_strcmp("55", array[0]) == 1) && (cli->isLogin == 0)) {
            client_error_unauthorized();
            break;
        } else if (my_strcmp(rfc_tab[i].name, array[0]) == 1) {
            rfc_tab[i].fnc(cli, array);
            ret = 1;
            break;
        }
    }
    return (ret);
}

int my_select_client(t_cli *cli, int res)
{
    FILE *fs = NULL;
    char *srv_line = NULL;
    char *new_line = NULL;
    char **tab = NULL;
    size_t servsize = 0;


    fs = fdopen(cli->sock, "rw");
    res = getline(&srv_line, &servsize, fs);
    if (res != -1) {
        new_line = my_clean_str(srv_line);
        if (new_line[0] != '\0') {
            tab = my_str_to_word_tab(new_line, ' ');
            my_rfcode(cli, tab);
        }
    }
    return (0);
}

int select_condition(t_cli *cli)
{
    char *clt_line = NULL;
    size_t size = 0;
    int res = 0;

    if (FD_ISSET(STDIN_FILENO, &cli->wrfs)) {
        res = getline(&clt_line, &size, stdin);
        if (res == -1)
            client_event_loggedout(cli->userid, cli->username);
        dprintf(cli->sock, "%s", clt_line);
    } else if (FD_ISSET(cli->sock, &cli->wrfs)) {
        my_select_client(cli, res);
    }
    return (0);
}
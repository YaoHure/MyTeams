/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_login
*/

#include "my_functions.h"
#include "logging_client.h"
#include "logging_server.h"

void connected(t_cli *cli, char **argv)
{
    if (argv && argv[1] != NULL && argv[2] != NULL) {
        client_event_loggedin(argv[1], argv[2]);
        cli->isLogin = 1;
        cli->username = strdup(argv[2]);
        cli->userid = strdup(argv[1]);
    }
}

void logout(t_cli *cli, char **argv)
{
    if (argv) {
        client_event_loggedout(argv[1], argv[2]);
        cli->isLogin = 2;
        if (cli->userid != NULL)
            free(cli->userid);
        if (cli->username != NULL)
            free(cli->username);
    }
}

int get_user_status(char *str_status)
{
    int ret = 0;
    if (my_strcmp(str_status, "true") == 1)
        ret = 1;
    return (ret);
}

void users(__attribute__((unused))t_cli *cli, char **argv)
{
    char **users = NULL;
    char **line = NULL;

    if (argv[1]) {
        line = my_str_to_word_array(argv[1], '/');
        for (int i = 0; line[i]; i++) {
            users = my_str_to_word_array(line[i], ':');
            client_print_users(users[1], users[0], get_user_status(users[2]));
        }
        my_free_array(line);
        my_free_array(users);
    }
}
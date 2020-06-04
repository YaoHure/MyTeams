/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_login
*/

#include "teams.h"
#include "my.h"
#include "logging_client.h"
#include "logging_server.h"

char *my_check_user_id(char **bdd, char *username)
{
    char **line = NULL;
    char *user_id = NULL;

    for (int i = 0; bdd[i]; i++) {
        line = my_str_to_word_array(bdd[i], ':');
        if (my_strcmp(line[0], username) == 1)
            user_id = strdup(line[1]);
    }
    my_free_array(line);
    return (user_id);
}

int check_user_data(char **bdd, char *username)
{
    int ret = 0;
    char **line = NULL;

    for (int i = 0; bdd[i]; i++) {
        line = my_str_to_word_array(bdd[i], ':');
        if (my_strcmp(line[0], username) == 1)
            ret++;
    }
    my_free_array(line);
    return (ret);
}
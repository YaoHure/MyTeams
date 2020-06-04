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

char *team_format(char *team_name, char *team_id, char **users_id)
{
    char *str = NULL;
    char *users = NULL;

    for (int i = 0; users_id[i]; i++) {
        if (i == 0) {
            users = strdup(users_id[i]);
        } else {
            users = strcat(users, ";");
            users = strcat(users, users_id[i]);
        }
    }
    str = my_strcat(team_name, ":");
    str = my_strcat(str, team_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, users);
    str = my_strcat(str, "\n");
    return (str);
}

char *channel_format(char *chn_name, char *chn_id, char *team_id)
{
    char *str = NULL;

    str = my_strcat(chn_name, ":");
    str = my_strcat(str, chn_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, team_id);
    str = my_strcat(str, "\n");
    return (str);
}

char *thread_format(char *th_name, char *th_id, char *user_id, char *msg)
{
    char *str = NULL;

    str = my_strcat(th_name, ":");
    str = my_strcat(str, th_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, user_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, msg);
    str = my_strcat(str, "\n");
    return (str);
}

char *reply_format(char *rp_name, char *rp_id, char *user_id, char *msg)
{
    char *str = NULL;

    str = my_strcat(rp_name, ":");
    str = my_strcat(str, rp_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, user_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, msg);
    str = my_strcat(str, "\n");
    return (str);
}

char *message_format(char *msg_id, char **users_id, char *user_id, char *msg)
{
    char *str = NULL;
    char *users = NULL;

    for (int i = 0; users_id[i]; i++) {
        if (i == 0) {
            users = strdup(users_id[i]);
        } else {
            users = strcat(users, ";");
            users = strcat(users, users_id[i]);
        }
    }
    str = my_strcat(msg_id, ":");
    str = my_strcat(str, users);
    str = my_strcat(str, ":");
    str = my_strcat(str, user_id);
    str = my_strcat(str, ":");
    str = my_strcat(str, msg);
    str = my_strcat(str, "\n");
    return (str);
}
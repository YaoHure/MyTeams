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

char *users_format(char *username, char *userid, char *islogin)
{
    char *str = NULL;

    str = my_strcat(username, ":");
    str = my_strcat(str, userid);
    str = my_strcat(str, ":");
    str = my_strcat(str, islogin);
    str = my_strcat(str, "\n");
    return (str);
}

char **change_user_status(char **bdd, char *username, char *islogin)
{
    int i = 0;
    char **line = NULL;
    char **new_bdd = malloc(sizeof(char *) * (my_len_array(bdd) + 1));

    for (; bdd[i]; i++) {
        line = my_str_to_word_array(bdd[i], ':');
        if (my_strcmp(line[0], username) == 1)
            new_bdd[i] = users_format(line[0], line[1], islogin);
        else
            new_bdd[i] = strdup(bdd[i]);
    }
    new_bdd[i] = NULL;
    my_free_array(line);
    my_free_array(bdd);
    return (new_bdd);
}

void my_login_add_user(t_teams *teams, t_server *srt, t_client *clt)
{
    char *str = NULL;

    teams->uuid_user = my_uuid();
    clt->userid = strdup(teams->uuid_user);
    str = users_format(teams->username, teams->uuid_user,
        my_strcat("true:", my_intostr(teams->cfd)));
    srt->bdd[USERS].my_bdd = add_item_to_db(srt->bdd[0].my_bdd, str);
    my_update_data_file(srt);
    free(str);
}

void my_login_same_user(t_teams *teams, t_server *srt, t_client *clt)
{
    teams->uuid_user = my_check_user_id(srt->bdd[USERS].my_bdd,
        teams->username);
    clt->userid = strdup(teams->uuid_user);
    srt->bdd[USERS].my_bdd = change_user_status(srt->bdd[0].my_bdd,
        teams->username, my_strcat("true:", my_intostr(teams->cfd)));
    my_update_data_file(srt);
}

void my_login(t_teams *teams, char **argv, t_server *srt, t_client *clt)
{
    int check = 0;

    if (my_len_array(argv) == 2 && my_check_arguments(argv[1]) == 2) check++;
    if (check == 1 && clt->username == NULL) {
        teams->username = strdup(my_skip_char(argv[1], '"'));
        clt->username = strdup(teams->username);
        if (check_user_data(srt->bdd[USERS].my_bdd, teams->username) != 1)
            my_login_add_user(teams, srt, clt);
        else
            my_login_same_user(teams, srt, clt);
        server_event_user_logged_in(teams->uuid_user);
        dprintf(teams->cfd, "%d %s %s\r\n", CONNECTED, teams->uuid_user,
        teams->username);
    }
}
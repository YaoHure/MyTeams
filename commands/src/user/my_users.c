/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_users
*/

#include "teams.h"
#include "macro.h"
#include "my.h"
#include "logging_client.h"
#include "logging_server.h"

char *my_skip_n(char *line)
{
    char *new_line = malloc(sizeof(char) * (strlen(line)));
    int i = 0;

    if (!new_line)
        return (NULL);
    for (; line[i] != '\n'; i++)
        new_line[i] = line[i];
    new_line[i] = '\0';
    return (new_line);
}

void print_usersname(t_teams *teams, t_server *srt)
{
    char **line = NULL;
    char *users_list = NULL;
    char *user_info = NULL;
    int j = 0;

    for (int i = 0; srt->bdd[USERS].my_bdd[i]; i++) {
        line = my_str_to_word_array(srt->bdd[USERS].my_bdd[i], ':');
        if (j == 0) {
            users_list = strdup(my_skip_n(srt->bdd[USERS].my_bdd[i]));
        } else {
            users_list = my_strcat(users_list, "/");
            user_info = my_skip_n(srt->bdd[USERS].my_bdd[i]);
            users_list = my_strcat(users_list, user_info);
        }
        j++;
    }
    dprintf(teams->cfd, "661 %s\r\n", users_list);
    my_free_array(line);
    free(user_info);
    free(users_list);
}

void my_users(t_teams *teams, __attribute__((unused))char **argv,
t_server *srt, t_client *clt)
{
    if (clt->username == NULL) {
        dprintf(teams->cfd, "Please login first.\r\n");
        client_error_unauthorized();
    } else {
        print_usersname(teams, srt);
    }
}

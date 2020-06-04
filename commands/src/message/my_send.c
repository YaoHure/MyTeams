/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_send
*/

#include "teams.h"
#include "my.h"
#include "logging_client.h"
#include "logging_server.h"

//send a message to a user stock the message for the
//BDD for the commande Messages

int get_user_fd(char **bdd, char *user_id)
{
    int fd = -1;
    char **line = NULL;

    for (int i = 0; bdd[i]; i++) {
        line = my_str_to_word_array(bdd[i], ':');
        if (line[3] && my_strcmp(user_id, line[1]) == 1) {
            fd = atoi(line[3]);
        }
    }
    my_free_array(line);
    return (fd);
}

void my_send(__attribute__((unused))t_teams *teams, char **argv,
t_server *srt, t_client *clt)
{
    int sentfd = 0;
    char *newmsg = NULL;
    char *newuid = NULL;

    if (argv && my_check_arguments(argv[1]) == 2 &&
        my_check_arguments(argv[2]) == 2) {
        newuid = strdup(my_skip_char(argv[1], '"'));
        newmsg = strdup(my_skip_char(argv[2], '"'));
        sentfd = get_user_fd(srt->bdd[USERS].my_bdd, newuid);
        server_event_private_message_sended(clt->userid, newuid, newmsg);
        dprintf(sentfd, "%d %s %s\r\n", MSG_SENT, clt->userid, newmsg);
        free(newmsg);
        free(newuid);
    }
}
/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_logout
*/

#include "teams.h"
#include "my.h"
#include "logging_client.h"
#include "logging_server.h"

void my_logout(t_teams *teams, __attribute__((unused))char **argv,
t_server *srt, t_client *clt)
{
    if (clt->userid != NULL) {
        server_event_user_logged_out(clt->userid);
        srt->bdd[USERS].my_bdd = change_user_status(srt->bdd[0].my_bdd,
                                clt->username, "false");
        my_update_data_file(srt);
        dprintf(teams->cfd, "%d %s %s\r\n", LOGGEDOUT, clt->userid,
                clt->username);
        clt->username = NULL;
        clt->logIn = 1;
    }
}

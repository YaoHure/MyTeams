/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_messages
*/

#include "macro.h"
#include "teams.h"
#include "my.h"

//list all messages exchange with an user need BDD //

void my_messages(t_teams *teams, __attribute__((unused))char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    if (teams->username == NULL) {
        dprintf(teams->cfd, "Please login first.\r\n");
    }
}

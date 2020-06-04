/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_unsubscribe
*/

#include "teams.h"

//List of all the unsubscribe channel need BDD//

void my_unsubscribe(t_teams *teams, __attribute__((unused))char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    dprintf(teams->cfd, "183 Unsubscribe work in progress.\r\n");
}

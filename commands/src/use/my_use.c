/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_use
*/

#include "teams.h"

//Print the UUID Channel Thread and Team need BDD//

void my_use(t_teams *teams, __attribute__((unused))char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    dprintf(teams->cfd, "320 Use work in progress.\r\n");
}

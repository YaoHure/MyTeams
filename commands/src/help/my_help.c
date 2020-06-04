/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_help
*/

#include "teams.h"

void my_help(t_teams *teams, __attribute__((unused)) char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    dprintf(teams->cfd, "214 Need help.Look at the documentation.\r\n");
}

/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_info
*/

#include "teams.h"

//Lister les infos de la BDD par rapport au USER

void my_info_use(void)
{
}

//Lister les infos de la BDD par rapport au TEAMS UUID

void my_info_teams(void)
{
}

//Lister les infos de la BDD par rapport au CHANNEL UUID en fonction du
//TEAMS UUID select au paravant

void my_info_channel(void)
{
}

//Lister les infos de la BDD par rapport au THREADS UUID en fonction du
//TEAMS UUID select et du CHANNEL UUID select au paravant

void my_info_threads(void)
{
}

// Lister les infos en bdd (user, channel, teams, thread)

void my_info(__attribute__((unused))t_teams *teams, char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    if (strcmp(argv[1], "teams_id"))
        my_info_teams();
    else if (strcmp(argv[1], "teams_id") && strcmp(argv[2], "channel_id"))
        my_info_channel();
    else if (strcmp(argv[1], "teams_id") && strcmp(argv[2], "channel_id")
        && strcmp(argv[3], "threads_id"))
        my_info_threads();
    else
        my_info_use();
}

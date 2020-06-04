/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_list
*/

#include "teams.h"

//List tout les teams créer présent dans la BDD

void my_list_teams(void)
{
}

//List tout les channels présent dans la BDD après select le teams en qustion

void my_list_channels(void)
{
}

//List tout les threads présent dans la BDD après select le teams puis
//le channel en question

void my_list_threads(void)
{
}

//List tout les threads channels et teams présent dans la BDD après
//SELECTION des ces trois derniers

void my_list_replies(void)
{
}

// Récupération des infos en BDD (team, channel, thread)

void my_list(__attribute__((unused))t_teams *teams, char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    if (strcmp(argv[1], "teams_uuid"))
        my_list_channels();
    else if (strcmp(argv[1], "teams_uid") && strcmp(argv[2], "channel_uid"))
        my_list_threads();
    else if (strcmp(argv[1], "teams_uid") && strcmp(argv[2], "channel_uid")
        && strcmp(argv[3], "threads_uuid"))
        my_list_replies();
    else
        my_list_teams();
}
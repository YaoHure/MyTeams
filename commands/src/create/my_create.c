/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_create
*/

#include "teams.h"
#include "my.h"

#include "logging_server.h"
#include "logging_client.h"

// créer une team dans la bdd.

void my_create_teams(t_teams *teams, char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    int i = 2;
    char *tmp = strdup((strlen(argv[i]) < 2) ? argv[i++] : argv[i]);

    if (teams->team == NULL) {
        server_event_team_created(argv[1], argv[1], teams->username);
        teams->team = strdup(argv[1]);
        teams->uuid_team = my_uuid();
        teams->team_description = tmp;
        dprintf(teams->cfd, "%d %s %s %s\r\n", TM_CREATED, teams->uuid_team,
            teams->team, teams->team_description);
    }

}

// Si team_uuid est set, créer un channel en BDD en précisant la team.

void my_create_channels(t_teams *teams, char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    int i = 2;
    char *tmp = strdup((strlen(argv[i]) < 2) ? argv[i++] : argv[i]);

    if (teams->channel == NULL) {
        server_event_channel_created(teams->team, argv[1], teams->username);
        teams->channel = strdup(argv[1]);
        teams->uuid_channel = my_uuid();
        teams->channel_description = tmp;
    }

}

// si team_uuid et channel_uuid sont set alors
// créer un nouveau thread en bdd en précisant le channel et la team.

void my_create_threads(t_teams *teams, char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    int i = 2;
    char *tmp = strdup((strlen(argv[i]) < 2) ? argv[i++] : argv[i]);

    if (teams->thread == NULL) {
        server_event_thread_created(teams->channel, argv[1],
            teams->username, tmp);
        teams->thread = strdup(argv[1]);
        teams->uuid_thread = my_uuid();
        teams->message = tmp;
    }
}

// Créer un commentaire sur un thread dans la bdd.
// Préciser la Team, le channel et le thread
// Il faut que team_uuid, channel_uuid et thread_uuid soit défini.

void my_create_reply(t_teams *teams, char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    teams->message = my_strcat(teams->message, my_strcat(" ; ", argv[1]));
    server_event_thread_new_message(teams->thread, teams->username, argv[1]);
}

void my_create(t_teams *teams, __attribute__((unused))char **argv,
__attribute__((unused))t_server *srt, __attribute__((unused))t_client *clt)
{
    if (teams->username == NULL) {
        dprintf(teams->cfd, "Please login first before create someting.\n\r");
    }
}

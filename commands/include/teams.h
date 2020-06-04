/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands
*/

#ifndef TEAMS_H_
#define TEAMS_H_

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/select.h>
#include <time.h>
#include <stdbool.h>
#include "server.h"
#include "macro.h"

typedef struct s_teams
{
    bool use;
    char *channel;
    char *username;
    char *channel_description;
    char *team;
    char *message;
    char *list_user;
    char *thread;
    char *uuid_user;
    char *uuid_team;
    char *uuid_channel;
    char *uuid_thread;
    char *team_description;
    int socket;
    int verif;
    int cfd;
    struct sockaddr_in addres;
    size_t current_receiving_byte;
} t_teams;

char **change_user_status(char **, char *, char *);
char *my_check_user_id(char **, char *);
int check_user_data(char **bdd, char *username);

void my_help(t_teams *, char **, t_server *, t_client *clt);
void my_login(t_teams *, char **, t_server *, t_client *clt);
void my_users(t_teams *, char **, t_server *, t_client *clt);
void my_user(t_teams *, char **, t_server *, t_client *clt);
void my_send(t_teams *, char **, t_server *, t_client *clt);
void my_messages(t_teams *, char **, t_server *, t_client *clt);
void my_subscribe(t_teams *, char **, t_server *, t_client *clt);
void my_subscribed(t_teams *, char **, t_server *, t_client *clt);
void my_unsubscribe(t_teams *, char **, t_server *, t_client *clt);
void my_use(t_teams *, char **, t_server *, t_client *clt);
void my_create(t_teams *, char **, t_server *, t_client *clt);
void my_list(t_teams *, char **, t_server *, t_client *clt);
void my_info(t_teams *, char **, t_server *, t_client *clt);
void my_logout(t_teams *, char **, t_server *, t_client *clt);

#endif /* !COMMANDS_H_ */

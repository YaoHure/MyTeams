/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "teams.h"
#include "server.h"

struct commands_s
{
    char *name;
    void (*fnc)(t_teams *, char **, t_server *, t_client *clt);
};

typedef struct commands_s commands_t;

commands_t commands_tab[] =
{
    {"/help", &my_help},
    {"/login", &my_login},
    {"/users", &my_users},
    {"/user", &my_user},
    {"/send", &my_send},
    {"/messages", &my_messages},
    {"/subscribe", &my_subscribe},
    {"/subscribed", &my_subscribed},
    {"/unsubscribe", &my_unsubscribe},
    {"/use", &my_use},
    {"/create", &my_create},
    {"/list", &my_list},
    {"/info", &my_info},
    {"/logout", &my_logout},
    {NULL, NULL}
};

extern commands_t commands_tab[];

#endif /* !COMMANDS_H_ */

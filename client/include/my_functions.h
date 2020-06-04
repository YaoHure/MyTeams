/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** MY_functions
*/

#ifndef MY_FUNCTIONS_H_
#define MY_FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/select.h>
#include <stdbool.h>
#include "server.h"
#include "macro.h"
#include "client.h"

// void my_help(char **);
void connected(t_cli *, char **);
void logout(t_cli *, char **);
void users(t_cli *, char **);
void msg_received(t_cli *, char **);
void print_created_teams(t_cli *, char **);
// void print_created_channel(t_cli *, char **);
// void print_created_threads(t_cli *, char **);
// void print_created_reply(t_cli *, char **);
// void my_users(char **);
// void my_user(char **);
// void my_send(char **);
// void my_messages(char **);
// void my_subscribe(char **);
// void my_subscribed(char **);
// void my_unsubscribe(char **);
// void my_use(char **);
// void my_create(char **);
// void my_list(char **);
// void my_info(char **);

#endif /* !MY_FUNCTIONS_H_ */

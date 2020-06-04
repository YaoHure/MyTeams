/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include "logging_client.h"

typedef struct s_cli
{
    int sock;
    int port;
    char *ip;
    int isLogin;
    char *username;
    char *userid;
    fd_set wrfs;
}t_cli;

int is_number(char *);
int check_ac(int);
int arg_check(int, char **);
int select_condition(t_cli *);
int init_con(t_cli *);
int socket_client(t_cli *);
int client_creation(char **);

#endif /* !CLIENT_H_ */

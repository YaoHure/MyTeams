/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include "../../database/include/bdd.h"
#include "../../utilities/include/my.h"

#define CLIENT_MAX 100

enum tab_nbr {
    USERS,
    TEAMS,
    CHANNELS,
    THREADS,
    COMMENTS,
    MESSAGES
};

typedef struct s_bdd {
    int number;
    char *bdd_name;
    char **my_bdd;
} t_bdd;

typedef struct s_client
{
    int socket;
    char *ip;
    char *username;
    char *userid;
    int logIn;
}t_client;

typedef struct s_server
{
    int port;
    char *ip;
    int ssock;
    int csock;
    int actual;
    int max;
    int res;
    fd_set rdfs;
    int fd;
    int line;
    char *file_name;
    char **data_file;
    char **bdd_tab_name;
    t_bdd *bdd;
} t_server;

int arg_check(int, char **);
int check_ac(int);
int is_number(char *);
int create_server(char **);
int socket_creation(t_server *);
void init_struct(t_server *);
void con_type(struct sockaddr_in *, int);
int socket_close(t_server *);
int bind_listen(int, struct sockaddr_in);
int sock_create(int);
int use_select(t_server *, struct sockaddr_in, socklen_t, int *);
int isaccepted(t_server *, t_client *);
int my_disconnect(t_server *, t_client *);
void remove_client(t_client *, int, int *);
int clt_handle(t_server *);
int select_cond(t_client *, t_server *);
int set_fdesc(t_server *, int, t_client *);
int writecli(int, char *);
char *delete_n(char *);

//my_bdd.c
void print_all_please(t_server *);
void my_update_data_file(t_server *);
char **add_item_to_db(char **, char *);
int init_struct_bdd(t_server *);
char *team_format(char *, char *, char **);
char *channel_format(char *, char *, char *);
char *thread_format(char *, char *, char *, char *);
char *reply_format(char *, char *, char *, char *);
char *message_format(char *, char **, char *, char *);

#endif /* !SERVER_H_ */

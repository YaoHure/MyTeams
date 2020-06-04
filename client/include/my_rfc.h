/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** rfc
*/

#ifndef MY_RFC_H_
#define MY_RFC_H_

#include "my_functions.h"

struct rfc_s
{
    char *name;
    void (*fnc)(t_cli *, char **);
};

typedef struct rfc_s rfc_t;

rfc_t rfc_tab[] =
{
    {"230", &connected},
    {"231", &logout},
    {"661", &users},
    {"360", &msg_received},
    {"450", &print_created_teams},
    {NULL, NULL}
};

extern rfc_t rfc_tab[];

#endif /* !MY_RFC_H_ */

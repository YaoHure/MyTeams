/*
** EPITECH PROJECT, 2020
** my_teams_bdd
** File description:
** my_bdd
*/

#include "../include/bdd.h"

void print_all_please(t_server *stdb)
{
    printf("_____________________________________\n");
    for (int i = 0; i <= MESSAGES; i++) {
        printf("struct = %d, bdd_name = %s", stdb->bdd[i].number,
            stdb->bdd_tab_name[i]);
        for (int x = 0; stdb->bdd[i].my_bdd[x]; x++) {
            printf("%s", stdb->bdd[i].my_bdd[x]);
        }
        printf("\n");
    }
}

void free_all_please(t_server *stdb)
{
    my_free_array(stdb->data_file);
    for (int i = 0; i <= MESSAGES; i++) {
        for (int x = 0; stdb->bdd[i].my_bdd[x]; x++) {
            free(stdb->bdd[i].my_bdd[x]);
        }
        free(stdb->bdd[i].my_bdd);
        free(stdb->bdd[i].bdd_name);
    }
    free(stdb->bdd);
}
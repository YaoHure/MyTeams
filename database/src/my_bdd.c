/*
** EPITECH PROJECT, 2020
** my_teams_bdd
** File description:
** my_bdd
*/

#include "../include/bdd.h"

void my_update_data_file(t_server *stdb)
{
    FILE *fp = fopen(stdb->file_name, "w+");
    for (int i = 0; i <= MESSAGES; i++) {
        fprintf(fp , "%s", stdb->bdd_tab_name[i]);
        for (int x = 0; stdb->bdd[i].my_bdd[x]; x++) {
            fprintf(fp , "%s", stdb->bdd[i].my_bdd[x]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

char **add_item_to_db(char **array, char *str)
{
    int i = 0;
    char **new_array = malloc(sizeof(char *) * (my_len_array(array) + 2));

    for (; array[i]; i++) {
        new_array[i] = strdup(array[i]);
    }
    new_array[i] = strdup(str);
    new_array[i+1] = NULL;
    array = my_free_array(array);
    return (new_array);
}

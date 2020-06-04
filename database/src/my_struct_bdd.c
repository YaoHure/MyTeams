/*
** EPITECH PROJECT, 2020
** my_teams_bdd
** File description:
** my_bdd
*/

#include "../include/bdd.h"

void bdd_to_array(int chk_nb, int start, int count_len, t_server *stdb)
{
    int loop = 0;

    stdb->bdd[chk_nb].my_bdd = malloc(sizeof(char *) * (count_len + 1));
    for (; loop < count_len; start++) {
        if (my_strcmp(stdb->data_file[start], "\n") != 1) {
            stdb->bdd[chk_nb].my_bdd[loop] = strdup(stdb->data_file[start]);
            loop++;
        }
    }
    stdb->bdd[chk_nb].my_bdd[loop] = NULL;
}

int my_init_array(int i, int chk_nb, t_server *stdb)
{
    int count_len = 0;
    int start_line = i;
    int ps = chk_nb + 1;

    for (; stdb->data_file[i]; i++) {
        if (ps != 6 && my_strcmp(stdb->data_file[i],
            stdb->bdd_tab_name[ps]) == 1)
            break;
        if (my_strcmp(stdb->data_file[i], "\n") != 1)
            count_len++;
    }
    stdb->bdd[chk_nb].number = chk_nb;
    stdb->bdd[chk_nb].bdd_name = strdup(stdb->bdd_tab_name[chk_nb]);
    bdd_to_array(chk_nb, start_line, count_len, stdb);
    return (i);
}

void my_get_bdd_list(t_server *stdb)
{
    int i = 0;
    int chk_nb = 0;

    for (i = 0; stdb->data_file[i];) {
        if (my_strcmp(stdb->data_file[i], stdb->bdd_tab_name[chk_nb]) == 1) {
            i++;
            i = my_init_array(i, chk_nb, stdb);
            chk_nb++;
        }
        else
            i++;
    }
}

int init_struct_bdd(t_server *stdb)
{
    char *array[] = { "[USERS]\n", "[TEAMS]\n", "[CHANNELS]\n", "[THREADS]\n",
            "[COMMENTS]\n" , "[MESSAGES]\n" , NULL};

    stdb->bdd = malloc(sizeof(t_bdd) * 6);
    stdb->fd = 0;
    stdb->line = 0;
    stdb->file_name = "./database/bdd.txt";
    stdb->data_file = fs_open_file(stdb->file_name);
    stdb->bdd_tab_name = my_dup_array(array);
    my_get_bdd_list(stdb);
    return (0);
}

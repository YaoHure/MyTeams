/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int my_strcmp(char const *, char const *);
char *my_uuid();
int my_strlen(char const *);
char *my_strcat(char *, char *);
char *my_clean_str(char *);
char **my_str_to_word_tab(char *, char );
char *my_strndup(char *, int );
char **my_dup_array(char **array);
char **my_free_array(char **array);
int my_len_array(char **array);
void my_printf_to_file(FILE *fp, char **array);
char **my_str_to_word_array(char *str, char separator);
char **fs_open_file(char *filepath);
int my_check_arguments(char *str);
char *my_skip_char(char *str, char c);
char *my_intostr(int nbr);

#endif /* !MY_H_ */

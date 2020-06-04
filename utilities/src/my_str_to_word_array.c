/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_len_array
*/

#include "../include/my.h"

char **malloc_double_array_word_by_word(char **array, char *str, char separator)
{
    int w = 0;
    int j = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != separator) {
            for (j = 0; str[i] != separator && i < len; i++, j++);
            array[w] = malloc(sizeof(char) * (j + 1));
            w++;
        }
    }
    return (array);
}

int my_count_word(char *str, char separator)
{
    int w = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != separator) {
            w++;
            for (; str[i] != separator && str[i]; i++);
        }
    }
    return (w);
}

char **my_str_to_word_array(char *str, char separator)
{
    char **array = malloc(sizeof(char *) * (my_count_word(str, separator) + 1));
    int w = 0;
    int j = 0;
    int x = 0;
    int start = 0;
    int len = strlen(str);

    array = malloc_double_array_word_by_word(array, str, separator);
    for (int i = 0; i < len; i++) {
        if (str[i] != separator) {
            start = i;
            for (j = 0; str[i] != separator && i < len; i++, j++);
            for (x = 0; start < i; x++, start++)
                array[w][x] = str[start];
            array[w][x] = '\0';
            w++;
        }
    }
    array[w] = NULL;
    return (array);
}

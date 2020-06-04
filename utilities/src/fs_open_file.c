/*
** EPITECH PROJECT, 2020
** my_teams_bdd
** File description:
** my_bdd
*/

#include "../include/my.h"

char **malloc_double_array_line_by_line(char **array, char *map)
{
    int i = 0;
    int j = 0;
    int a = 0;

    for (i = 0; map[i] != '\0'; i++, a++) {
        for (j = 0; map[i] != '\n'; i++, j++);
        array[a] = malloc(sizeof(char) * (j + 2));
    }
    array[a] = NULL;
    return (array);
}

char **my_map_to_double_array(char *map, int size)
{
    char **array = malloc(sizeof(char *) * (size + 1));
    int x = 0;
    int y = 0;
    int z = 0;

    array = malloc_double_array_line_by_line(array, map);
    for (; array[y] != NULL && map[z] != '\0'; z++, y++) {
        for (x = 0; map[z] != '\n'; array[y][x] = map[z], z++, x++);
        array[y][x] = '\n';
        array[y][x + 1] = '\0';
    }
    array[y] = NULL;
    return (array);
}

int nb_file_byte(char *filepath)
{
    struct stat s;

    stat(filepath, &s);
    return (s.st_size);
}

char **my_get_array(int fd, char *buffer, int count)
{
    char **mapping = NULL;
    int size = read(fd, buffer, count);

    if (buffer[count - 1] == '\0') {
        buffer[count] = '\0';
        mapping = my_map_to_double_array(buffer, size);
    } else {
        buffer[count - 1] = '\0';
        mapping = my_map_to_double_array(strcat(buffer, "\n"), size);
    }
    return (mapping);
}

char **fs_open_file(char *filepath)
{
    int count = nb_file_byte(filepath);
    char *buffer = malloc(sizeof(char) * count + 1);
    char **mapping = NULL;
    int fd = open(filepath, O_CREAT | O_RDWR , 0664);

    if (fd == -1)
        return (NULL);
    else
        mapping = my_get_array(fd, buffer, count);
    free(buffer);
    close(fd);
    return (mapping);
}

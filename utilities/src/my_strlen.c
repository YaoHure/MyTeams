/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

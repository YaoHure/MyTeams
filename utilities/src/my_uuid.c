/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** my_uuid
*/

#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>

char *my_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(sizeof(char) * 37);

    uuid_generate(binuuid);
    uuid_unparse(binuuid, uuid);
    return (uuid);
}
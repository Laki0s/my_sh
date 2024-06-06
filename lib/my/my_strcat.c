/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

#include "./my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int lien = my_strlen(dest);

    for (; src[i] != '\0'; i++)
        dest[lien + i] = src[i];
    dest[lien + i] = '\0';
    return dest;
}

/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int taille = my_strlen(src);
    char *str = malloc((sizeof(char) * taille) + 1);
    int i = 0;

    while (i < taille) {
        str[i] = src[i];
        i++;
    }
    str[taille] = '\0';
    return str;
}

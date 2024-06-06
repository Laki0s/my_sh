/*
** EPITECH PROJECT, 2024
** minishell2rendu
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *cpy_str(char *dest, char *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}

int nb_of_lines(char *str, char sep)
{
    int cp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
            cp++;
    }
    return cp + 1;
}

char **my_str_to_array(char *str, char sep)
{
    int lines = nb_of_lines(str, sep);
    int x = 0;
    char **map = malloc((lines + 1) * sizeof(char *));
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; j++) {
        for (; str[i] == sep && str[i] != '\0'; i++);
        if (str[i] == '\0')
            break;
        for (x = i; str[x] != sep && str[x] != '\0'; x++);
        map[j] = malloc((x - i + 1) * sizeof(char));
        cpy_str(map[j], &str[i], x - i);
        i = x;
    }
    map[j] = NULL;
    return map;
}

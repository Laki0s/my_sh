/*
** EPITECH PROJECT, 2023
** octal
** File description:
** octal
*/

#include "my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_o(va_list list)
{
    int re = va_arg(list, int);
    int o = 0;
    int good = 1;

    while (re > 0) {
        o += (re % 8) * good;
        re /= 8;
        good *= 10;
    }
    my_put_nbr(o);
    return (0);
}

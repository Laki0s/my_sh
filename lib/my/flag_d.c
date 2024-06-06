/*
** EPITECH PROJECT, 2023
** flag_d
** File description:
** flag_d
*/

#include "my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_d(va_list list)
{
    int value = va_arg(list, int);

    my_put_nbr(value);
    return (0);
}

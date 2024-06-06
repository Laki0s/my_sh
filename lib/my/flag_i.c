/*
** EPITECH PROJECT, 2023
** flag_i
** File description:
** flag_i
*/

#include "my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_i(va_list list)
{
    int value = va_arg(list, int);

    my_put_nbr(value);
    return (0);
}

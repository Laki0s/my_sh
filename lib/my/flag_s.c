/*
** EPITECH PROJECT, 2023
** flag_s
** File description:
** flag_s
*/

#include "my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_s(va_list list)
{
    char *str = va_arg(list, char *);

    if (str) {
        my_putstr(str);
    }
    return 0;
}

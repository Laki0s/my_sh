/*
** EPITECH PROJECT, 2023
** test
** File description:
** tes
*/

#include "my.h"
#include "mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int codingstyle(char *x, char flag, va_list list)
{
    int (*tab[8]) (va_list) = {flag_c, flag_d, flag_s, flag_i,
    flag_pourcent, flag_o, flag_x, flag_f};

    for (int i = 0; i < 8; i++) {
        if (flag == x[i]){
            tab[i](list);
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    char x[8] = {'c', 'd', 's', 'i', '%', 'o', 'x', 'f'};
    char flag;

    va_start(list, format);
    while (*format) {
        if (*format == '%'){
            format++;
            flag = *format;
            codingstyle(x, flag, list);
        } else {
            my_putchar(*format);
        }
        format++;
    }
    va_end(list);
    return 0;
}

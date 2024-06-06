/*
** EPITECH PROJECT, 2023
** B-CPE-101-NCY-1-1-myprintf-quentin.gehin
** File description:
** flag_c
*/

#include "my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_c(va_list list)
{
    char chara = va_arg(list, int);

    my_putchar(chara);
    return (0);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-101-NCY-1-1-myprintf-quentin.gehin
** File description:
** flag_x
*/

#include "my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_x(va_list list)
{
    char hexa[] = "0123456789ABCDEF";
    char hexa_str[9];
    unsigned int num = va_arg(list, unsigned int);
    int base = 0;

    for (int i = 0; i < 8; i++) {
        base = (num >> (28 - i * 4)) & 0xF;
        hexa_str[i] = hexa[base];
        my_putchar(hexa_str[i]);
    }
    hexa_str[8] = '\0';
    return 0;
}

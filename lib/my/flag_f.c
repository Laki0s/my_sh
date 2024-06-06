/*
** EPITECH PROJECT, 2023
** B-CPE-101-NCY-1-1-myprintf-quentin.gehin
** File description:
** flag_f
*/

#include "../../include/my.h"
#include "../../include/mylist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int flag_f(va_list list)
{
    double num = va_arg(list, double);
    int integerPart = (int)num;
    double fractionalPart = num - integerPart;
    int digit;

    my_printf("%d.", integerPart);
    for (int i = 0; i < 6; i++) {
        fractionalPart *= 10;
        digit = (int)fractionalPart;
        my_printf("%d", digit);
        fractionalPart -= digit;
    }
    return 0;
}

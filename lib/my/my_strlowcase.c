/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

char *my_strlowcase(char *str)
{
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str = *str - 'A' + 'a';
        }
        str++;
    }
    return str;
}

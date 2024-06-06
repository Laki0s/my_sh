/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

int my_strlen(char const *str)
{
    int strnumb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        strnumb++;
    }
    return (strnumb);
}

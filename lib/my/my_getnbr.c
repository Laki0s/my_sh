/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

int sign_calc(const char *str, int i, int sign, int result)
{
    int digit = 0;

    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        digit = str[i] - '0';
        if (result >= (2147483648 - digit) / 10) {
            return (0);
        }
        result = result * 10 + digit;
        i++;
    }
    return (sign * result);
}

int my_getnbr(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    sign_calc(str, i, sign, result);
}

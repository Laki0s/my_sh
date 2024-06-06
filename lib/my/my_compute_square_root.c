/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

int my_compute_square_root(int nb)
{
    int result;

    result = 1;
    if (nb < 0) {
        return (0);
    }
    for (int i = 0; i >= 0 && i <= nb; i++) {
        if (i * i == nb) {
            result = i;
        }
    }
    return (result);
}

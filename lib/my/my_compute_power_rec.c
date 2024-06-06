/*
** EPITECH PROJECT, 2023
** UwU
** File description:
** OwO
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    if (p > 1) {
        return my_compute_power_rec(nb * nb, p - 1);
    }
}

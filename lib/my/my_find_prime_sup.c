/*
** EPITECH PROJECT, 2023
** OwO
** File description:
** UwU
*/

int my_is_prime2(int nb)
{
    if (nb <= 1) {
        return (0);
    }
    for (int i = 2; i * i <= nb; i++) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    while (my_is_prime2(nb) == 0) {
        nb++;
    }
    return (nb);
}

/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        nb = 0;
    while (my_is_prime(nb) == 0) {
        my_is_prime(nb + 1);
        nb = nb + 1;
    }
    return (nb);
}

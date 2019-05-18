/*
** EPITECH PROJECT, 2018
** main_functions
** File description:
** main_functions
*/

#include "include/my.h"
#include "include/bistromatic.h"
#include <unistd.h>
#include <stdlib.h>

int is_neg(char *nb, char *opes)
{
    int is_neg = 1;

    for (int i = 0; nb[i] == opes[OP_SUB] ||
        nb[i] == opes[OP_ADD]; i++)
        if (nb[i] == opes[OP_SUB])
            is_neg = is_neg * (-1);
    return (is_neg);
}

int base_to_nbr(char *base, char nb)
{
    int nbr = 0;
    int i = 0;

    while (base[i] != '\0') {
        if (base[i] == nb)
            nbr = i;
        i = i + 1;
    }
    return (nbr);
}
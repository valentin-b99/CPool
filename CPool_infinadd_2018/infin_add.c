/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** 
*/

#include "include/my.h"
#include "include/complement.h"
#include <stdlib.h>

void calculate_add(char *nb1, char *nb2, int neg)
{
    char *result = malloc(sizeof(char) * my_strlen(nb1) + 3);
    int curr_nb;
    int carr_nbr = 0;

    result[my_strlen(nb1) + 2] = '\0';
    for (int i = my_strlen(nb1) - 1; i >= 0; i--) {
        curr_nb = (nb1[i] - 48) + (nb2[i] - 48) + carr_nbr;
        if (curr_nb > 9) {
            carr_nbr = 1;
            curr_nb = curr_nb % 10;
        }
        else
            carr_nbr = 0;
        result[i + 2] = curr_nb + 48;
    }
    display_nbr(add_neg_carr(result, carr_nbr, neg));
    free(result);
}

void calculate_sub(char *nb1, char *nb2, int neg)
{
    char *result = malloc(sizeof(char) * my_strlen(nb1) + 3);
    int curr_nb;
    int carr_nbr = 0;

    result[my_strlen(nb1) + 2] = '\0';
    for (int i = my_strlen(nb1) - 1; i >= 0; i--) {
        curr_nb = (nb1[i] - 48) - ((nb2[i] - 48) + carr_nbr);
        if (curr_nb < 0) {
            curr_nb = ((nb1[i] - 48) + 10) - ((nb2[i] - 48) + carr_nbr);
            carr_nbr = 1;
        }
        else
            carr_nbr = 0;
        result[i + 2] = curr_nb + 48;
    }
    display_nbr(add_neg_carr(result, carr_nbr, neg));
    free(result);
}

void add(char *nb1, char *nb2, int neg)
{
    for (int i = 0; nb1[i] == '-' || nb1[i] == '+'; i++)
        nb1[i] = '0';
    for (int i = 0; nb2[i] == '-' || nb2[i] == '+'; i++)
        nb2[i] = '0';
    if (my_strlen(nb1) > my_strlen(nb2))
        nb2 = equalize_nbr(nb1, nb2);
    else if (my_strlen(nb2) > my_strlen(nb1))
        nb1 = equalize_nbr(nb2, nb1);
    calculate_add(nb1, nb2, neg);
}

void sub(char *nb1, char *nb2, int neg_nb1, int neg_nb2)
{
    for (int i = 0; nb1[i] == '-' || nb1[i] == '+'; i++)
        nb1[i] = '0';
    for (int i = 0; nb2[i] == '-' || nb2[i] == '+'; i++)
        nb2[i] = '0';
    if (my_strlen(nb1) > my_strlen(nb2))
        nb2 = equalize_nbr(nb1, nb2);
    else if (my_strlen(nb2) > my_strlen(nb1))
        nb1 = equalize_nbr(nb2, nb1);
    if (my_strcmp(nb1, nb2) < 0)
        calculate_sub(nb1, nb2, neg_nb1);
    else
        calculate_sub(nb2, nb1, neg_nb2);
}

int main(int ac, char **av)
{
    if (test_error(ac, av) == 84)
        return (84);
    if (is_neg(av[1]) == is_neg(av[2]))
        add(av[1], av[2], is_neg(av[1]));
    else
        sub(av[1], av[2], is_neg(av[1]), is_neg(av[2]));
    return (0);
}
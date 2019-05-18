/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** make an infinit addition
*/

#include "../include/my.h"
#include "../include/functions_infin_add.h"
#include "../include/bistromatic.h"
#include <stdlib.h>

char *calculate_add(char *nb1, char *nb2, int neg, char **base)
{
    char *result = malloc(sizeof(char) * my_strlen(nb1) + 3);
    int curr_nb;
    int carr_nbr = 0;

    result[my_strlen(nb1) + 2] = '\0';
    for (int i = my_strlen(nb1) - 1; i >= 0; i--) {
        curr_nb = base_to_nbr(base[ARR_NBR], nb1[i]) +
        base_to_nbr(base[ARR_NBR], nb2[i]) + carr_nbr;
        if (curr_nb > my_strlen(base[ARR_NBR]) - 1) {
            carr_nbr = 1;
            curr_nb = curr_nb % my_strlen(base[ARR_NBR]);
        }
        else
            carr_nbr = 0;
        result[i + 2] = base[ARR_NBR][curr_nb];
    }
    return (add_neg_carr(result, carr_nbr, neg, base));
    free(result);
}

char *calculate_sub(char *nb1, char *nb2, int neg, char **base)
{
    char *result = malloc(sizeof(char) * my_strlen(nb1) + 3);
    int curr_nb;
    int carr_nbr = 0;

    result[my_strlen(nb1) + 2] = '\0';
    for (int i = my_strlen(nb1) - 1; i >= 0; i--) {
        curr_nb = base_to_nbr(base[ARR_NBR], nb1[i]) -
        (base_to_nbr(base[ARR_NBR], nb2[i]) + carr_nbr);
        if (curr_nb < 0) {
            curr_nb = (base_to_nbr(base[ARR_NBR], nb1[i]) +
            my_strlen(base[ARR_NBR])) - (base_to_nbr(base[ARR_NBR], nb2[i]) +
            carr_nbr);
            carr_nbr = 1;
        }
        else
            carr_nbr = 0;
        result[i + 2] = base[ARR_NBR][curr_nb];
    }
    return (add_neg_carr(result, carr_nbr, neg, base));
    free(result);
}

char *add(char *nb1, char *nb2, int neg, char **base)
{
    for (int i = 0; nb1[i] == base[ARR_OPS][OP_SUB] ||
        nb1[i] == base[ARR_OPS][OP_ADD]; i++)
        nb1[i] = base[ARR_NBR][0];
    for (int i = 0; nb2[i] == base[ARR_OPS][OP_SUB] ||
        nb2[i] == base[ARR_OPS][OP_ADD]; i++)
        nb2[i] = base[ARR_NBR][0];
    if (my_strlen(nb1) > my_strlen(nb2))
        nb2 = equalize_nbr(nb1, nb2, base);
    else if (my_strlen(nb2) > my_strlen(nb1))
        nb1 = equalize_nbr(nb2, nb1, base);
    return (calculate_add(nb1, nb2, neg, base));
}

char *sub(char *nb1, char *nb2, int *neg, char **base)
{
    for (int i = 0; nb1[i] == base[ARR_OPS][OP_SUB] ||
        nb1[i] == base[ARR_OPS][OP_ADD]; i++)
        nb1[i] = base[ARR_NBR][0];
    for (int i = 0; nb2[i] == base[ARR_OPS][OP_SUB] ||
        nb2[i] == base[ARR_OPS][OP_ADD]; i++)
        nb2[i] = base[ARR_NBR][0];
    if (my_strlen(nb1) > my_strlen(nb2))
        nb2 = equalize_nbr(nb1, nb2, base);
    else if (my_strlen(nb2) > my_strlen(nb1))
        nb1 = equalize_nbr(nb2, nb1, base);
    if (my_strcmp(nb1, nb2) < 0)
        return (calculate_sub(nb1, nb2, neg[0], base));
    else
        return (calculate_sub(nb2, nb1, neg[1], base));
}

char *main_infin_add(char *nb1, char *nb2, char **base)
{
    int neg[2];

    if (is_neg(nb1, base[ARR_OPS]) == is_neg(nb2, base[ARR_OPS])) {
        return (add(nb1, nb2, is_neg(nb1, base[ARR_OPS]), base));
    } else {
        neg[0] = is_neg(nb1, base[ARR_OPS]);
        neg[1] = is_neg(nb2, base[ARR_OPS]);
        return (sub(nb1, nb2, neg, base));
    }
}
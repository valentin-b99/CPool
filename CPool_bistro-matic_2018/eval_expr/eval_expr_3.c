/*
** EPITECH PROJECT, 2018
** eval_expr_3
** File description:
** eval_expr_3
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_eval_expr.h"
#include <stdlib.h>

int charisinbase(char const str, char *base)
{
    for (int i = 0; base[i] != 0; i++)
        if (str == base[i])
            return (1);
    return (0);
}

char *add_neg_structless(int neg, char *result, char *opes)
{
    char *tmp;

    if (neg == -1) {
        tmp = malloc(sizeof(char) * my_strlen(result) + 1);
        tmp[0] = opes[OP_SUB];
        return (my_strcat(tmp, result));
    }
    return (result);
}

char *my_getstrnbr(char const *str, struct main_inputs inputs)
{
    char *number = malloc(sizeof(char) * my_strlen(str) + 1);
    int len_nombre = 0;
    int is_neg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == inputs.opes[OP_SUB]) {
            is_neg = is_neg * (-1);
        } else if (charisinbase(str[i], inputs.base) &&
        !(charisinbase(str[i + 1], inputs.base))) {
            number[len_nombre] = str[i];
            return (add_neg_structless(is_neg, number, inputs.opes));
        }
        if (charisinbase(str[i], inputs.base) &&
        str[i] != inputs.opes[OP_SUB]) {
            number[len_nombre] = str[i];
            len_nombre++;
        }
    }
    return (add_neg_structless(is_neg, number, inputs.opes));
}

int how_many_res(char *av, char *base)
{
    int nbrint;

    for (int i = 0; av[i] != 0; i++)
        if (charisinbase(av[i], base) && !charisinbase(av[i + 1], base))
            nbrint++;
    return (nbrint);
}
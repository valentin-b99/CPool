/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** eval_expr
*/

#include "include/my.h"
#include "include/my_opp.h"
#include "include/my_functions.h"
#include <stdlib.h>

char *priority(char *av, int j)
{
    char *result;
    int operator = -1;
    int k = j;

    for (; av[k] != ')'; k++)
        for (int i = 0; i < 5; i++)
            SET_OP(av, k, i);
    if (operator == -1) {
        result = malloc(sizeof(char) * my_strlen((int_to_char(
        my_getnbr(av + j + 1)))));
        result = int_to_char(my_getnbr(av + j + 1));
    } else {
        result = malloc(sizeof(char) * my_strlen(int_to_char(
        OPE_FUNCS[operator].funct(my_getnbr(av + j + 1),
        my_getnbr(av + START_NBR(av, j) + 1)))));
        result = int_to_char(OPE_FUNCS[operator].funct(my_getnbr(av + j + 1),
        my_getnbr(av + START_NBR(av, j) + 1)));
    }
    return (my_insertstrcat(j, k + 1, result, av));
}

int calculate(char *av)
{
    int i = 0;
    int j = 0;

    while (av[i] != 0) {
        if (av[i] == '(')
            j = i;
        else if (av[i] == ')')
            return (CALCULATE(av, j));
        i++;
    }
}

char *insert_par_next(char *av, int *i, int op)
{
    if (av[*i] == *OPE_FUNCS[op].ope) {
        if (my_charisnum(av[*i - 1]))
            av = prev_isnum(av, *i);
        else if (av[*i - 1] == ')')
            av = prev_ispar(av, *i);
        *i += 1;
        if (my_charisnum(av[*i + 1]))
            av = next_isnum(av, *i + 1);
        else if (av[*i + 1] == '(')
            av = next_ispar(av, *i + 2);
        *i += 1;
    }
    return (av);
}

int eval_expr(char *av)
{
    av = insert_par(av);
    return (calculate(av));
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
/*
** EPITECH PROJECT, 2018
** eval_expr_2
** File description:
** next of eval_expr
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_eval_expr.h"
#include <stdlib.h>

char *prev_isnum(struct main_inputs inputs, int i)
{
    char par[2] = {inputs.opes[OP_OPEN_PAR], '\0'};

    while (charisinbase(inputs.expr[i - 1], inputs.base))
        i--;
    inputs.expr = my_insertstrcat(i, i, par, inputs.expr);
    return (inputs.expr);
}

char *next_isnum(struct main_inputs inputs, int i)
{
    char par[2] = {inputs.opes[OP_CLOSE_PAR], '\0'};

    while (charisinbase(inputs.expr[i], inputs.base))
        i++;
    inputs.expr = my_insertstrcat(i, i, par, inputs.expr);
    return (inputs.expr);
}

char *prev_ispar(struct main_inputs inputs, int i)
{
    int par = 1;
    char *tmp = malloc(sizeof(char) * (my_strlen(inputs.expr) + 1));
    char parc[2] = {inputs.opes[OP_OPEN_PAR], '\0'};

    i = i - 2;
    while (i >= 0) {
        if (inputs.expr[i] == inputs.opes[OP_CLOSE_PAR])
            par++;
        else if (inputs.expr[i] == inputs.opes[OP_OPEN_PAR])
            par--;
        if (par == 0) {
            my_strcpy(tmp, inputs.expr);
            inputs.expr = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            inputs.expr = my_insertstrcat(i, i, parc, tmp);
            return (inputs.expr);
        }
        i--;
    }
}

char *next_ispar(struct main_inputs inputs, int i)
{
    int par = 1;
    char *tmp = malloc(sizeof(char) * (my_strlen(inputs.expr) + 1));
    char parc[2] = {inputs.opes[OP_CLOSE_PAR], '\0'};

    while (inputs.expr[i] != '\0') {
        if (inputs.expr[i] == inputs.opes[OP_CLOSE_PAR])
            par++;
        else if (inputs.expr[i] == inputs.opes[OP_OPEN_PAR])
            par--;
        if (par == 0) {
            my_strcpy(tmp, inputs.expr);
            inputs.expr = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            inputs.expr = my_insertstrcat(i, i, parc, tmp);
            return (inputs.expr);
        }
        i++;
    }
    return (inputs.expr);
}

char *insert_par(struct main_inputs inputs)
{
    char par_op[2] = {inputs.opes[0], '\0'};
    char par_cl[2] = {inputs.opes[1], '\0'};

    inputs.expr = my_insertstrcat(0, 0, par_op, inputs.expr);
    inputs.expr = my_insertstrcat(my_strlen(inputs.expr),
    my_strlen(inputs.expr), par_cl, inputs.expr);
    inputs.expr = my_insertstrcat(0, 0, par_op, inputs.expr);
    inputs.expr = my_insertstrcat(my_strlen(inputs.expr),
    my_strlen(inputs.expr), par_cl, inputs.expr);
    for (int i = 0; inputs.expr[i] != '\0'; i++)
        for (int op = OP_MUL; op <= OP_MOD; op++)
            inputs.expr = insert_par_next(inputs, &i, op);
    for (int i = 0; inputs.expr[i] != '\0'; i++)
        for (int op = OP_ADD; op <= OP_SUB; op++)
            inputs.expr = insert_par_next(inputs, &i, op);
    return (inputs.expr);
}
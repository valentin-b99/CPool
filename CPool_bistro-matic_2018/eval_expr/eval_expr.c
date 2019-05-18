/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** eval_expr
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_eval_expr.h"
#include <stdlib.h>

char *priority(struct main_inputs inputs, int j)
{
    int operator = -1;
    int k = j;
    const struct operator OPE_FUNCS[] = {{inputs.opes[OP_ADD], &my_add},
        {inputs.opes[OP_SUB], &my_sub}, {inputs.opes[OP_MUL], &my_mul},
        {inputs.opes[OP_DIV], &my_div}, {inputs.opes[OP_MOD], &my_mod}};

    for (; inputs.expr[k] != inputs.opes[OP_CLOSE_PAR]; k++)
        for (int i = OP_ADD; i <= OP_MOD; i++)
            SET_OP(inputs.expr, inputs.opes, k, i);
    if (operator == -1) {
        return (my_insertstrcat(j, k + 1, GETNBR(inputs, j),
        inputs.expr));
    } else  {
        return (my_insertstrcat(j, k + 1, OPE_FUNCS[operator].funct(
        GETNBR(inputs, j), my_getstrnbr(inputs.expr + (j + 1 + my_strlen(
        GETNBR(inputs, j))) + 1, inputs), inputs), inputs.expr));
    }
}

char *calculate_next(struct main_inputs inputs, int j)
{
    if (how_many_res(inputs.expr, inputs.base) == 1) {
        return (my_getstrnbr(priority(inputs, j), inputs));
    } else {
        inputs.expr = priority(inputs, j);
        return (calculate(inputs));
    }
}

char *calculate(struct main_inputs inputs)
{
    int i = 0;
    int j = 0;

    while (inputs.expr[i] != 0) {
        if (inputs.expr[i] == inputs.opes[OP_OPEN_PAR])
            j = i;
        else if (inputs.expr[i] == inputs.opes[OP_CLOSE_PAR])
            return (calculate_next(inputs, j));
        i++;
    }
}

char *insert_par_next(struct main_inputs inputs, int *i, int op)
{
    if (inputs.expr[*i] == inputs.opes[op]) {
        if (charisinbase(inputs.expr[*i - 1], inputs.base))
            inputs.expr = prev_isnum(inputs, *i);
        else if (inputs.expr[*i - 1] == inputs.opes[OP_CLOSE_PAR])
            inputs.expr = prev_ispar(inputs, *i);
        *i += 1;
        if (charisinbase(inputs.expr[*i + 1], inputs.base))
            inputs.expr = next_isnum(inputs, *i + 1);
        else if (inputs.expr[*i + 1] == inputs.opes[OP_OPEN_PAR])
            inputs.expr = next_ispar(inputs, *i + 2);
        *i += 1;
    }
    return (inputs.expr);
}

char *eval_expr(struct main_inputs inputs)
{
    inputs.expr = insert_par(inputs);
    return (calculate(inputs));
}
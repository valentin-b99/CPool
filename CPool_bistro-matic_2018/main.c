/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/bistromatic.h"
#include "include/functions_errors.h"
#include "include/functions_eval_expr.h"
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    char *expr;
    struct main_inputs inputs = {.base = av[1], .opes = av[2]};

    test_errors_syntax(ac, av);
    expr = get_expr(my_getnbr(av[ARG_LEN]));
    test_errors_expr(expr, av);
    expr = fix_expr(expr, av[ARG_OP]);
    inputs.expr = expr;
    my_putstr(eval_expr(inputs));
    my_putchar('\n');
    return (EXIT_SUCCESS);
}
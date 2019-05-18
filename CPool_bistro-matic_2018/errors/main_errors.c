/*
** EPITECH PROJECT, 2018
** main_errors
** File description:
** main_errors
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_errors.h"
#include <stdlib.h>
#include <unistd.h>

void test_errors_syntax(int ac, char **av)
{
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(USAGE_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (my_strlen(av[ARG_BASE]) < 2 || test_sim_char_in_str(av[ARG_BASE])) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    if (my_strlen(av[ARG_OP]) != 7 || test_sim_char_in_str(av[ARG_OP])) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

char *get_expr(int const size)
{
    char *expr;
    int len;
    int offset = 0;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * (size + 1));
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

void test_errors_expr(char const *expr, char **av)
{
    for (int i = 0; expr[i] != 0; i++) {
        if (!test_sim_char_btw_str(expr[i], av[ARG_BASE]) &&
        !test_sim_char_btw_str(expr[i], av[ARG_OP])) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_EXPR_FAIL);
        }    
    }
}

int count_par(char const *expr, char const *ops)
{
    int par = 0;

    for (int i = 0; expr[i] != 0; i++) {
        if (expr[i] == ops[OP_OPEN_PAR])
            par++;
        if (expr[i] == ops[OP_CLOSE_PAR])
            par--;
        if (par < 0) {
            my_putstr(ERROR_MSG);
            exit(EXIT_PAR);
        }
    }
    return (par);
}

char *fix_expr(char *expr, char const *ops)
{
    int par = count_par(expr, ops);
    char *tmp = malloc(sizeof(char) * (my_strlen(expr) + 1));
    int i = 0;

    for (int i = OP_ADD; i <= OP_MOD; i++)
        if (expr[my_strlen(expr) - 1] == ops[i])
            expr[my_strlen(expr) - 1] = 0;
    my_strcpy(tmp, expr);
    expr = malloc(sizeof(char) * (my_strlen(tmp) + par + 1));
    my_strcpy(expr, tmp);
    while (par > 0) {
        expr[my_strlen(tmp) + i] = ops[OP_CLOSE_PAR];
        i++;
        par--;
    }
    expr[my_strlen(tmp) + i] = 0;
    return (expr);
}
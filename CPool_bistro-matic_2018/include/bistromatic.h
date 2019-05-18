/*
** EPITECH PROJECT, 2018
** bistromatic.h
** File description:
** bistromatic
*/

#ifndef BISTROMATIC_H_
# define BISTROMATIC_H_

/*Exit numbers*/
# define EXIT_SUCCESS    0
# define EXIT_USAGE      84
# define EXIT_BASE       84
# define EXIT_OPS        84
# define EXIT_SIZE_NEG   84
# define EXIT_MALLOC     84
# define EXIT_READ       84
# define EXIT_PAR        84
# define EXIT_EXPR_FAIL  84

/*Error messages*/
# define USAGE_ERROR_MSG     " base ops\"()+-*/%\" exp_len\n"
# define SYNTAX_ERROR_MSG    "syntax error\n"
# define ERROR_MSG           "error\n"

/*Location of arguments*/
# define ARG_BASE    1
# define ARG_OP      2
# define ARG_LEN     3

/*Location of operators*/
# define OP_OPEN_PAR     0
# define OP_CLOSE_PAR    1
# define OP_ADD          2
# define OP_SUB          3
# define OP_MUL          4
# define OP_DIV          5
# define OP_MOD          6

/*Location of array infin add*/
# define ARR_NBR 0
# define ARR_OPS 1

#endif /* !BISTROMATIC_H_ */

int is_neg(char *, char *);
int base_to_nbr(char *, char);

struct main_inputs
{
    char *expr;
    char *base;
    char *opes;
};
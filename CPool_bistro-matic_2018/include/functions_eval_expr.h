/*
** EPITECH PROJECT, 2018
** functions_eval_expr
** File description:
** functions_eval_expr
*/

#ifndef FUNCTIONS_EVAL_EXPR_H_
# define FUNCTIONS_EVAL_EXPR_H_

struct operator
{
    char ope;
    char *(*funct)(char *, char *, struct main_inputs);
};

char *priority(struct main_inputs, int);
char *calculate_next(struct main_inputs, int);
char *calculate(struct main_inputs);
char *insert_par_next(struct main_inputs, int *, int);
char *eval_expr(struct main_inputs);
char *prev_isnum(struct main_inputs, int);
char *next_isnum(struct main_inputs, int);
char *prev_ispar(struct main_inputs, int);
char *next_ispar(struct main_inputs, int);
char *insert_par(struct main_inputs);
int charisinbase(char const, char *);
char *my_getstrnbr(char const *, struct main_inputs);
char *add_neg_structless(int, char *, char *);
int how_many_res(char *, char *);

char *my_add(char *, char *, struct main_inputs);
char *my_sub(char *, char *, struct main_inputs);
char *my_div(char *, char *, struct main_inputs);
char *my_mul(char *, char *, struct main_inputs);
char *my_mod(char *, char *, struct main_inputs);

# define GETNBR(inputs, j) (my_getstrnbr(inputs.expr + j + 1, inputs))
# define SET_OP(av, op, k, i) if (av[k] == op[i]) operator = i - 2;

#endif /* !FUNCTIONS_EVAL_EXPR_H_ */

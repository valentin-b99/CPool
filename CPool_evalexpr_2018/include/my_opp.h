/*
** EPITECH PROJECT, 2018
** my_opp
** File description:
** my_opp
*/

#ifndef MY_OPP_H_
#define MY_OPP_H_

int my_add(int nb1, int nb2);
int my_sub(int nb1, int nb2);
int my_div(int nb1, int nb2);
int my_mul(int nb1, int nb2);
int my_mod(int nb1, int nb2);

struct	operator
{
    char *ope;
    int	(*funct)(int, int);
};

const struct operator OPE_FUNCS[] =
{
    {"+", &my_add},
    {"-", &my_sub},
    {"/", &my_div},
    {"*", &my_mul},
    {"%", &my_mod},
};

#define START_NBR(av, j) (j + 1 + my_strlen(int_to_char(my_getnbr(av + j + 1))))
#define SET_OP(av, k, i) if (av[k] == *OPE_FUNCS[i].ope) operator = i;
#define CALCULATE(av, j) (how_many_int(priority(av, j)) == 1) ? \
my_getnbr(priority(av, j)) : calculate(priority(av, j))
#endif /* !MY_OPP_H_ */
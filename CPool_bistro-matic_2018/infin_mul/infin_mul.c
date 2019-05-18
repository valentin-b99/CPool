/*
** EPITECH PROJECT, 2018
** multiplication infinit
** File description:
** can manage all base to multiplication
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_infin_mul.h"
#include "../include/functions_infin_add.h"
#include <unistd.h>
#include <stdlib.h>

struct calc_mul refresh_first_add(struct calc_mul calc,
struct mul_inputs inputs)
{
    char *tmp;
    char *base[2] = {inputs.base, inputs.opes};

    if (calc.carr_nbr > 0){
        calc.last_add[calc.cnt_decate] = inputs.base[calc.carr_nbr];
        calc.carr_nbr = 0;
    }
    calc.last_add = my_revstr(calc.last_add);
    tmp = malloc(sizeof(char) * my_strlen(calc.first_add) + 1);
    my_strcpy(tmp, calc.first_add);
    calc.first_add = malloc(sizeof(char) * my_strlen(calc.last_add) + 1);
    my_strcpy(calc.first_add, main_infin_add(calc.last_add, tmp, base));
    return (calc);
}

struct calc_mul calc_mul_next(struct calc_mul calc,
struct mul_inputs inputs, int i, int j)
{
    calc.curr_nb = base_to_nbr(inputs.base, inputs.nb2[j]) *
    base_to_nbr(inputs.base, inputs.nb1[i]) + calc.carr_nbr;
    calc.carr_nbr = (calc.curr_nb - calc.curr_nb %
    my_strlen(inputs.base)) / my_strlen(inputs.base);
    calc.curr_nb = calc.curr_nb % my_strlen(inputs.base);
    calc.last_add[calc.cnt_decate] = inputs.base[calc.curr_nb];
    calc.cnt_decate++;
    return (calc);
}

char *calculate_mul(struct mul_inputs inputs)
{
    struct calc_mul calc = {.carr_nbr = 0, .cnt_decate = 0};

    calc.first_add = malloc(sizeof(char) * 1);
    calc.first_add[0] = inputs.base[0];
    for (int j = my_strlen(inputs.nb2) - 1; j >= 0; j--) {
        calc.last_add = malloc(sizeof(char) * (2 * my_strlen(inputs.nb1)
        + 1 - j));
        calc.cnt_decate = 0;
        for (int m = 0; m < my_strlen(inputs.nb2) - 1 - j; m++) {
            calc.last_add[calc.cnt_decate] = inputs.base[0];
            calc.cnt_decate++;
        }
        for (int i = my_strlen(inputs.nb1) - 1; i >= 0; i--)
            calc = calc_mul_next(calc, inputs, i, j);
        calc = refresh_first_add(calc, inputs);
    }
    return (add_neg(inputs, calc.first_add));
}

char *mul(struct mul_inputs inputs)
{
    for (int i = 0; inputs.nb1[i] == inputs.opes[OP_SUB] ||
        inputs.nb1[i] == inputs.opes[OP_ADD]; i++)
        inputs.nb1[i] = inputs.base[0];
    for (int i = 0; inputs.nb2[i] == inputs.opes[OP_SUB] ||
        inputs.nb2[i] == inputs.opes[OP_ADD]; i++)
        inputs.nb2[i] = inputs.base[0];
    return (calculate_mul(inputs));
}

char *main_infin_mul(struct mul_inputs inputs)
{
    char *tmp;

    if (is_neg(inputs.nb1, inputs.opes) != is_neg(inputs.nb2, inputs.opes))
        inputs.neg = -1;
    if (inputs.nb1[0] == inputs.opes[OP_SUB])
        inputs.nb1[0] = inputs.base[0];
    if (inputs.nb2[0] == inputs.opes[OP_SUB])
        inputs.nb2[0] = inputs.base[0];
    if (my_strlen(inputs.nb1) < my_strlen(inputs.nb2)) {
        tmp = malloc(sizeof(char) * my_strlen(inputs.nb1) + 1);            
        my_strcpy(tmp, inputs.nb1);
        my_strcpy(inputs.nb1, inputs.nb2);
        my_strcpy(inputs.nb2, tmp);
    }
    return (mul(inputs));
}
/*
** EPITECH PROJECT, 2018
** operators
** File description:
** operators for eval expr
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_infin_add.h"
#include "../include/functions_infin_mul.h"
#include <stdlib.h>

char *my_add(char *nb1, char *nb2, struct main_inputs inputs)
{
    char *base[2] = {inputs.base, inputs.opes};

    return (main_infin_add(nb1, nb2, base));
}

char *my_sub(char *nb1, char *nb2, struct main_inputs inputs)
{
    char *base[2] = {inputs.base, inputs.opes};
    char *tmp = malloc(sizeof(char) * my_strlen(nb2));
    
    my_strcpy(tmp, nb2);
    nb2 = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    nb2[0] = inputs.opes[OP_SUB];
    my_strcat(nb2, tmp);
    return (main_infin_add(nb1, nb2, base));
}

char *my_div(char *nb1, char *nb2, struct main_inputs inputs)
{
    char *base = malloc(sizeof(char) * 2);
    base[0] = inputs.base[0];
    base[1] = '\0';
    return (base);
}

char *my_mul(char *nb1, char *nb2, struct main_inputs inputs)
{
    struct mul_inputs mul_inputs = {.nb1 = nb1, .nb2 = nb2,
        .base = inputs.base, .opes = inputs.opes};

    return (main_infin_mul(mul_inputs));
}

char *my_mod(char *nb1, char *nb2, struct main_inputs inputs)
{
    char *base = malloc(sizeof(char) * 2);
    base[0] = inputs.base[0];
    base[1] = '\0';
    return (base);
}
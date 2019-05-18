/*
** EPITECH PROJECT, 2018
** infin_mul2
** File description:
** infin_mul2
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_infin_mul.h"
#include "../include/functions_infin_add.h"
#include <unistd.h>
#include <stdlib.h>

char *add_neg(struct mul_inputs inputs, char *first_add)
{
    char *tmp;

    if (inputs.neg == -1) {
        tmp = malloc(sizeof(char) * my_strlen(first_add) + 1);
        tmp[0] = inputs.opes[OP_SUB];
        return (my_strcat(tmp, first_add));
    }
    return (first_add);
}
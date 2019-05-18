/*
** EPITECH PROJECT, 2018
** infin_add2
** File description:
** infin_add2
*/

#include "../include/my.h"
#include "../include/functions_infin_add.h"
#include "../include/bistromatic.h"
#include <stdlib.h>

char *equalize_nbr(char *max, char *min, char **base)
{
    char *tmp = malloc(sizeof(char) * my_strlen(min) + 1);
    int count;

    my_strcpy(tmp, min);
    min = malloc(sizeof(char) * (my_strlen(max) * 2));
    count = my_strlen(max) - my_strlen(tmp);
    for (int i = 0; i < count; i++)
        min[i] = base[ARR_NBR][0];
    for (int i = 0; i < my_strlen(max); i++)
        min[count + i] = tmp[i];
    free(tmp);
    return (min);
}

char *add_neg_carr(char *result, int carr_nbr, int neg, char **base)
{
    int i = 0;
    char *zero = malloc(sizeof(char) * 2);

    zero[0] = base[ARR_NBR][0];
    zero[1] = 0;
    result[0] = base[ARR_NBR][0];
    result[1] = base[ARR_NBR][0];
    if (carr_nbr == 1)
        result[1] = base[ARR_NBR][1];
    while (result[i] == base[ARR_NBR][0])
        i++;
    if (result[i] == 0)
        return (zero);
    if (neg == -1) {
        i--;
        result[i] = base[ARR_OPS][OP_SUB];
    }
    result = result + i;
    return (result);
}
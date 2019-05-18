/*
** EPITECH PROJECT, 2018
** complement
** File description:
** 
*/

#include "include/my.h"
#include <stdlib.h>

int test_error(int ac, char **av)
{
    if (ac < 3 || ac > 3)
        return (84);
    if (my_str_isnum_with_add_and_sub(av[1]) != 1)
        return (84);
    if (my_str_isnum_with_add_and_sub(av[2]) != 1)
        return (84);
}

int is_neg(char *nb)
{
    int is_neg = 1;

    for (int i = 0; nb[i] == '-' || nb[i] == '+'; i++)
        if (nb[i] == '-')
            is_neg = is_neg * (-1);
    return (is_neg);
}

char *equalize_nbr(char *max, char *min)
{
    char *tmp = malloc(sizeof(char) * my_strlen(min) + 1);
    int count;

    my_strcpy(tmp, min);
    min = malloc(sizeof(char) * (my_strlen(max) * 2));
    count = my_strlen(max) - my_strlen(tmp);
    for (int i = 0; i < count; i++)
        min[i] = '0';
    for (int i = 0; i < my_strlen(max); i++)
        min[count + i] = tmp[i];
    free(tmp);
    return (min);
}

char *add_neg_carr(char *result, int carr_nbr, int neg)
{
    result[0] = '0';
    result[1] = '0';
    if (carr_nbr == 1)
        result[1] = '1';
    if (neg < 0)
        result[0] = '-';
    return (result);
}

void display_nbr(char *result)
{
    int i = 0;
    int test_zero = 1;

    for (int j = 0; result[j] != '\0'; j++)
        if (result[j] != '0' && result[j] != '-')
            test_zero = 0;
    if (test_zero == 1)
        my_putchar('0');
    else {
        if (result[i] == '-') {
            my_putchar('-');
            i++;
        }
        while (result[i] == '0')
            i++;
        for (;result[i] != '\0'; i++)
            my_putchar(result[i]);
    }
    my_putchar('\n');
}

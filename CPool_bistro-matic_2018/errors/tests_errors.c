/*
** EPITECH PROJECT, 2018
** tests_errors
** File description:
** test_errors
*/

#include "../include/my.h"
#include "../include/bistromatic.h"
#include "../include/functions_errors.h"
#include <stdlib.h>
#include <unistd.h>

int test_sim_char_in_str(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        for (int j = 0; str[j] != 0; j++)
            TESTSICH(str, i, j);
    return (0);
}

int test_sim_char_btw_str(char const cr, char const *av)
{
    for (int i = 0; av[i] != 0; i++)
        if (cr == av[i])
            return (1);
    return (0);
}
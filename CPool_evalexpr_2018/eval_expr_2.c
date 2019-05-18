/*
** EPITECH PROJECT, 2018
** eval_expr_2
** File description:
** next of eval_expr
*/

#include "include/my.h"
#include "include/my_functions.h"
#include <stdlib.h>

char *prev_isnum(char *av, int i)
{
    while (my_charisnum(av[i - 1]))
        i--;
    av = my_insertstrcat(i, i, "(", av);
    return (av);
}

char *next_isnum(char *av, int i)
{
    while (my_charisnum(av[i]))
        i++;
    av = my_insertstrcat(i, i, ")", av);
    return (av);
}

char *prev_ispar(char *av, int i)
{
    int par = 1;
    char *tmp = malloc(sizeof(char) * (my_strlen(av) + 1));

    i = i - 2;
    while (i >= 0) {
        if (av[i] == ')')
            par++;
        else if (av[i] == '(')
            par--;
        if (par == 0) {
            my_strcpy(tmp, av);
            av = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            av = my_insertstrcat(i, i, "(", tmp);
            return (av);
        }
        i--;
    }
}

char *next_ispar(char *av, int i)
{
    int par = 1;
    char *tmp = malloc(sizeof(char) * (my_strlen(av) + 1));

    while (av[i] != '\0') {
        if (av[i] == '(')
            par++;
        else if (av[i] == ')')
            par--;
        if (par == 0) {
            my_strcpy(tmp, av);
            av = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            av = my_insertstrcat(i, i, ")", tmp);
            return (av);
        }
        i++;
    }
    return (av);
}

char *insert_par(char *av)
{
    for (int i = 0; av[i] != '\0'; i++)
        for (int op = 2; op < 5; op++)
            av = insert_par_next(av, &i, op);
    for (int i = 0; av[i] != '\0'; i++)
        for (int op = 0; op < 2; op++)
            av = insert_par_next(av, &i, op);
    return (av);
}
/*
** EPITECH PROJECT, 2018
** my_insertstrcat
** File description:
** my_inserstrcat
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_insertstrcat(int first, int end, char *nb, char *av)
{
    char *str1 = malloc(sizeof(char) * (first + 1));
    char *str2 = av + end;
    char *result = malloc(sizeof(char) *
    (my_strlen(av) - (end - first) + my_strlen(nb)));

    str1 = my_strncpy(str1, av, first);
    my_strcat(result, my_strdup(str1));
    my_strcat(result, nb);
    my_strcat(result, str2);
    return (result);
}
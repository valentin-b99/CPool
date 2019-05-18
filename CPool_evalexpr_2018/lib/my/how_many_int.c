/*
** EPITECH PROJECT, 2018
** how_many_int
** File description:
** how_many_int
*/

#include "../../include/my.h"

int how_many_int(char *av)
{
    int nbrint;

    for (int i = 0; av[i] != 0; i++)
        if (my_charisnum(av[i]) && !my_charisnum(av[i + 1]))
            nbrint++;
    return (nbrint);
}
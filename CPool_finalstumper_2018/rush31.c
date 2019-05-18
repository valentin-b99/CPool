/*
** EPITECH PROJECT, 2018
** rush3 1
** File description:
** next of rush 3
*/

#include "include/my.h"

void display_particular(int col_x, int col_y)
{
    my_putstr("[rush1-3] ");
    my_put_nbr(col_x);
    my_putchar(' ');
    my_put_nbr(col_y);
    my_putstr(" || [rush1-4] ");
    my_put_nbr(col_x);
    my_putchar(' ');
    my_put_nbr(col_y);
    my_putstr(" || [rush1-5] ");
    my_put_nbr(col_x);
    my_putchar(' ');
    my_put_nbr(col_y);
    my_putchar('\n');
}

void display(int rush, int col_x, int col_y)
{
    my_putstr("[rush1-");
    my_put_nbr(rush);
    my_putstr("] ");
    my_put_nbr(col_x);
    my_putchar(' ');
    my_put_nbr(col_y);
    my_putchar('\n');
}
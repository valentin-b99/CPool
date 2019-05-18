/*
** EPITECH PROJECT, 2018
** display_percents
** File description:
** 
*/

int    display_percents(int nb)
{
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
    return (0);
}

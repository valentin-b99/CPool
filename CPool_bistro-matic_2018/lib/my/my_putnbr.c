/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** my_putnbr
*/

#include "../../include/my.h"

void extrem_min(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb == -2147483648) {
        extrem_min();
    } else if (nb > 9) {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

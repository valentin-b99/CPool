/*
** EPITECH PROJECT, 2018
** rush2-3
** File description:
** 
*/

#include <stdlib.h>
#include "include/my.h"

int    count_tot_char(char *str)
{
    int result = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            result--;
    return (result);
}

int    display_float(int nb)
{
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
    return (0);
}

void    display_nbr(int ac, char *str, char *letter, char *letter_inv)
{
    int nbr = 0;

    for (int l = 0; l < ac - 2; l++) {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] == letter[l] || str[i] == letter_inv[l])
                nbr++;
        my_putchar(letter[l]);
        my_putchar(':');
        my_put_nbr(nbr);
        my_putstr(" (");
        display_float(10000 * nbr / count_tot_char(str));
        my_putstr("%)");
        my_putchar('\n');
        nbr = 0;
    }
}

int    main(int ac, char **av)
{
    char *str = av[1];
    char *letter = malloc(sizeof(char) * (ac - 2));
    char *letter_inv = malloc(sizeof(char) * (ac - 2));

    for (int i = 0; i < ac - 2; i++) {
        letter[i] = av[i + 2][0];
        if (my_strlen(av[i + 2]) > 1 || ((letter[i] < 65 || letter[i] > 90) &&
            (letter[i] < 97 || letter[i] > 122)))
            return (84);
        if (letter[i] >= 65 && letter[i] <= 90)
            letter_inv[i] = letter[i] + 32;
        if (letter[i] >= 97 && letter[i] <= 122)
            letter_inv[i] = letter[i] - 32;
    }
    display_nbr(ac, str, letter, letter_inv);
    return (0);
}

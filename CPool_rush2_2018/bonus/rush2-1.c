/*
** EPITECH PROJECT, 2018
** rush2-1
** File description:
** 
*/

#include "include/my.h"

int    main(int ac, char **av)
{
    char *str = av[1];
    char letter = av[2][0];
    char letter_inv;
    int nbr = 0;

    if (ac > 3 || my_strlen(av[2]) > 1 || ((letter < 65 || letter > 90) &&
        (letter < 97 || letter > 122)))
        return (84);
    if (letter >= 65 && letter <= 90)
        letter_inv = letter + 32;
    if (letter >= 97 && letter <= 122)
        letter_inv = letter - 32;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == letter || str[i] == letter_inv)
            nbr++;
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(nbr);
    my_putchar('\n');
    return (0);
}

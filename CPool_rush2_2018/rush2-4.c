/*
** EPITECH PROJECT, 2018
** rush2-4
** File description:
** 
*/

#include <stdlib.h>
#include "include/my.h"
#include "include/alphabet.h"

int    count_tot_char(char *str)
{
    int result = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            result--;
    return (result);
}

int     find_lang(int per, char letter)
{
    int result[2];

    result[0] = 10000;
    for (int i = 0; i < 4; i++) {
        if (((alpha[letter - 97][i] * 100) - per) > 0 &&
        ((alpha[letter - 97][i] * 100) - per) < result[0]) {
            result[0] = (alpha[letter - 97][i] * 100) - per;
            result[1] = i;
        }
        if (((alpha[letter - 97][i] * 100) - per) < 0 &&
        (per - (alpha[letter - 97][i] * 100)) < result[0]) {
            result[0] = per - (alpha[letter - 97][i] * 100);
            result[1] = i;
        }
    }
    return (result[1]);
}

void    display_lang(int *langs)
{
    int score = 0;
    int lang_find;

    for (int i = 0; i < 4; i++) {
        if (langs[i] > score) {
            score = langs[i];
            lang_find = i;
        }
    }
    if (lang_find == 0)
        my_putstr("=> English\n");
    if (lang_find == 1)
        my_putstr("=> French\n");
    if (lang_find == 2)
        my_putstr("=> German\n");
    if (lang_find == 3)
        my_putstr("=> Spanish\n");
}

void    next_main(char *str)
{
    int langs[4] = {0, 0, 0, 0};

    for (int i = 0; i < 26; i++) {
        if (find_lang(10000 * calc_nbr(97 + i, str) / count_tot_char(str),
	    97 + i) == 0)
            langs[0]++;
        if (find_lang(10000 * calc_nbr(97 + i, str) / count_tot_char(str),
	    97 + i) == 1)
            langs[1]++;
        if (find_lang(10000 * calc_nbr(97 + i, str) / count_tot_char(str),
	    97 + i) == 2)
            langs[2]++;
        if (find_lang(10000 * calc_nbr(97 + i, str) / count_tot_char(str),
	    97 + i) == 3)
            langs[3]++;
    }
    display_lang(langs);
}

int    main(int ac, char **av)
{
    char *str = av[1];
    int nbr;

    for (int i = 0; i < ac - 2; i++)
        if (my_strlen(av[i + 2]) > 1 || ((av[i + 2][0] < 65 ||
	    av[i + 2][0] > 90) && (av[i + 2][0] < 97 || av[i + 2][0] > 122)))
            return (84);
    for (int l = 2; l < ac; l++) {
	nbr = calc_nbr_args(l, str, av);
        my_putchar(av[l][0]);
        my_putchar(':');
        my_put_nbr(nbr);
        my_putstr(" (");
        display_percents(10000 * nbr / count_tot_char(str));
        my_putstr("%)");
        my_putchar('\n');
    }
    next_main(str);
    return (0);
}

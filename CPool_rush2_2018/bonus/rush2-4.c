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
    if (letter >= 65 && letter <= 90)
        letter = letter + 32;
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

void    display_nbr(int ac, char *str, char *letter, char *letter_inv)
{
    int nbr = 0;
    int langs[4] = {0, 0, 0, 0};
    
    for (int l = 0; l < ac - 2; l++) {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] == letter[l] || str[i] == letter_inv[l])
		nbr++;
        my_putchar(letter[l]);
        my_putchar(':');
        my_put_nbr(nbr);
        my_putstr(" (");
        display_percents(10000 * nbr / count_tot_char(str));
        my_putstr("%)");
        my_putchar('\n');
        for (int i = 0; i < 4; i++)
            if (find_lang(10000 * nbr / count_tot_char(str), letter[l]) == i)
		langs[i]++;
        nbr = 0;
    }
    display_lang(langs);
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

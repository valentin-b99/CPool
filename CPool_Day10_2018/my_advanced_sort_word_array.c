/*
** EPITECH PROJECT, 2018
** my_advanced_sort_word_array
** File description:
** 
*/

#include "include/my.h"

int    fp_cmp(char *s1, char *s2)
{
    my_strcmp(s1, s2);
}

int    my_advanced_sort_word_array(char **tab,
int(*cmp)(char const *, char const *))
{
    char *temp;

    cmp = &fp_cmp;
    for (int i = 0; i < my_arraylen(tab) - 1; i++) {
        if (cmp(tab[i], tab[i + 1]) < 0) {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = -1;
        }
    }
    return (0);
}

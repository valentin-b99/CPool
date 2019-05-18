/*
** EPITECH PROJECT, 2018
** match
** File description:
** 
*/

#include "include/my.h"

void    next_match(char const *s1, char const *s2, int *j, int *i)
{
    while (s1[*i] != s2[*j] && s2[*j] != 0) {
        *j += 1;
    }
    if (s2[*j] == 0 && (s1[my_strlen(s1) - 1] == s2[*j - 1] ||
        s2[*j - 1] == '*' ))
        *i = my_strlen(s1);
}

int    match(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while ((s1[i] == s2[j] || s2[j] == '*') && s1[i] != 0) {
        i++;
        if (s2[j] == '*')
            next_match(s1, s2, &j, &i);
        j++;
    }
    if (i == my_strlen(s1))
        return (1);
    return (0);
}

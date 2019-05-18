/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** my_strcapitalize
*/

#include "../../include/my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase(str);
    while (str[i] != '\0') {
        if ((str[i - 1] < 48 || str[i - 1] > 58) &&
            (str[i - 1] < 65 || str[i - 1] > 90) &&
            (str[i - 1] < 95 || str[i - 1] > 122) &&
            (str[i] <= 122 && str[i] >= 97))
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

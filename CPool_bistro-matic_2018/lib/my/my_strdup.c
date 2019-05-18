/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

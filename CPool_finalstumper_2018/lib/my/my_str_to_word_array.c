/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"
#include <stdlib.h>

int count_words(char const *str)
{
    int i = 0;
    int col = 0;

    while (str[i] != '\0') {
        if (my_charisalpha(str[i]) == 0 && my_charisnum(str[i]) == 0 &&
            (my_charisalpha(str[i - 1]) == 1 || my_charisnum(str[i - 1]) == 1 ||
            i == 0))
            col++;
        i++;
    }
    if (my_charisalpha(str[i - 1]) == 1 || my_charisnum(str[i - 1]) == 1)
        col++;
    return (col);
}

int word_len(char const *str, int i)
{
    int len = 0;

    while (my_charisalpha(str[i]) == 1 || my_charisnum(str[i]) == 1) {
        len++;
        i++;
    }
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    char **dest = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char *stock;
    int j = 0;
    int col = 0;

    for (int i = 0; str[i] != '\0' && col < count_words(str); i++) {
        stock = malloc(sizeof(char) * (word_len(str, i) + 1));
        for (; my_charisalpha(str[i]) == 1 || my_charisnum(str[i]) == 1; j++) {
            stock[j] = str[i];
            i++;
        }
        if (j > 0) {
            stock[j] = '\0';
            dest[col] = stock;
            col++;
        }
        j = 0;
    }
    dest[col] = NULL;
    return (dest);
}

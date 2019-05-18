/*
** EPITECH PROJECT, 2018
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            return (0);
        i++;
    }
    return (1);
}

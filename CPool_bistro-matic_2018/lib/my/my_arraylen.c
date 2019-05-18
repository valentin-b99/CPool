/*
** EPITECH PROJECT, 2018
** my_arraylen
** File description:
** my_arraylen
*/

int my_arraylen(char const *str[])
{
    int i = 0;

    while (str[i] != 0) {
        i = i + 1;
    }
    return (i);
}

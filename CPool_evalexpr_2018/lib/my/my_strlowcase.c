/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

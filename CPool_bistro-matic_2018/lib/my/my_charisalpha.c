/*
** EPITECH PROJECT, 2018
** my_charisalpha
** File description:
** my_charisalpha
*/

int my_charisalpha(char const str)
{
    if ((str < 65 || str > 90) && (str < 97 || str > 122))
        return (0);
    return (1);
}

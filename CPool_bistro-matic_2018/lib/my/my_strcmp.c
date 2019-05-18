/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if (s1[i] > s2[i])
        return (-1);
    else if (s1[i] < s2[i])
        return (1);
    else
        return (0);
}

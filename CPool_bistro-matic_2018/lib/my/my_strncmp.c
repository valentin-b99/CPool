/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int score;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
        i++;
    if (s1[i] > s2[i])
        return (-1);
    else if (s1[i] < s2[i])
        return (1);
    else
        return (0);
}

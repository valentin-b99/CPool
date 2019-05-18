/*
** EPITECH PROJECT, 2018
** my_sort_params
** File description:
** 
*/
#include <unistd.h>

void    my_putchar(char);

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    my_putchar('\n');
    return (0);
}

int    my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int score;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if (s1[i] > s2[i])
        return (-1);
    else if (s1[i] < s2[i])
        return (1);
    else
        return (0);
}

int    main(int ac, char **av)
{
    int i = 0;
    char *temp;

    while (i < ac - 1) {
        if (my_strcmp(av[i], av[i + 1]) < 0) {
            temp = av[i];
            av[i] = av[i + 1];
            av[i + 1] = temp;
            i = 0;
        } else {
            i++;
        }
    }
    i = 0;
    while (i < ac) {
        my_putstr(av[i]);
        i++;
    }
    return (0);
}

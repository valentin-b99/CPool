/*
** EPITECH PROJECT, 2018
** rush2-4-2
** File description:
** 
*/

int    calc_nbr_args(int l, char *str, char **av)
{
    int nbr = 0;
    char letter_inv;

    for (int i = 0; str[i] != '\0'; i++) {
        if (av[l][0] >= 65 && av[l][0] <= 90)
            letter_inv = av[l][0] + 32;
        if (av[l][0] >= 97 && av[l][0] <= 122)
            letter_inv = av[l][0] - 32;
        if (str[i] == av[l][0] || str[i] == letter_inv)
            nbr++;
    }
    return (nbr);
}

int    calc_nbr(int l, char *str)
{
    int nbr = 0;
    char letter_inv;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == l || str[i] == l - 32)
            nbr++;
    }
    return (nbr);
}

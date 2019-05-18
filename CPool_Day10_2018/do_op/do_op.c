/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** 
*/

#include "../include/my.h"

int    my_getnbrv2(char const *str)
{
    long number = 0;
    int is_neg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45)
            is_neg = is_neg * (-1);
        else if ((str[i] >= 48 && str[i] <= 57) &&
            (str[i + 1] < 48 || str[i + 1] > 57)) {
            number = number * 10 + (str[i] - 48);
            return (number * is_neg);
        } else if (str[i] >= 48 && str[i] <= 57)
            number = number * 10 + (str[i] - 48);
        else if ((str[i] < 48 || str[i] > 57) && str[i] != 43)
            return (number * is_neg);
        number = number * is_neg;
        if (number < -2147483648 || number > 2147483647)
            return (0);
        number = number * is_neg;
    }
    return (number * is_neg);
}

void    do_op(char **av)
{
    if (av[2][0] == '+')
        my_put_nbr(my_getnbrv2(av[1]) + my_getnbrv2(av[3]));
    if (av[2][0] == '-')
        my_put_nbr(my_getnbrv2(av[1]) - my_getnbrv2(av[3]));
    if (av[2][0] == '*')
        my_put_nbr(my_getnbrv2(av[1]) * my_getnbrv2(av[3]));
    if (av[2][0] == '/')
        my_put_nbr(my_getnbrv2(av[1]) / my_getnbrv2(av[3]));
    if (av[2][0] == '%')
        my_put_nbr(my_getnbrv2(av[1]) % my_getnbrv2(av[3]));
}

int    main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if (av[2][0] != 37 && av[2][0] != 42 && av[2][0] != 43 &&
        av[2][0] != 45 && av[2][0] != 47) {
        my_put_nbr(0);
        my_putchar('\n');
        return (84);
    }
    if (av[2][0] == 47 && my_getnbrv2(av[3]) == 0) {
        my_putstr("Stop: division by zero\n");
        return (84);
    }
    if (av[2][0] == 37 && my_getnbrv2(av[3]) == 0) {
        my_putstr("Stop: modulo by zero\n");
        return (84);
    }
    do_op(av);
    my_putchar('\n');
    return (0);
}

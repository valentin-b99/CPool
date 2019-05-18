/*
** EPITECH PROJECT, 2018
** my_advanced_do-op
** File description:
** 
*/

#include "../include/my.h"
#include "../include/my_opp_struct.h"
#include "../include/my_opp.h"

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

void    my_usage(void)
{
    my_putstr("error: only [ ");
    for (int j = 0; j < 5; j++) {
        my_putstr(OPERATORS_FUNCS[j].operator);
        my_putchar(' ');
    }
    my_putstr("] are supported\n");
}

int    main(int ac, char **av)
{
    int i = 0;

    if (ac != 4)
        return (84);
    while (i < 5 && *av[2] != *OPERATORS_FUNCS[i].operator)
        i++;
    if (i == 5) {
        my_usage();
        return (84);
    }
    if (i == 2 && my_getnbrv2(av[3]) == 0) {
        my_putstr("Stop: division by zero\n");
        return (84);
    }
    if (i == 4 && my_getnbrv2(av[3]) == 0) {
        my_putstr("Stop: modulo by zero\n");
        return (84);
    }
    OPERATORS_FUNCS[i].function(my_getnbrv2(av[1]), my_getnbrv2(av[3]));
    my_putchar('\n');
    return (0);
}

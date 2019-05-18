/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    long number = 0;
    int is_neg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45)
            is_neg = is_neg * (-1);
        else if ((str[i] >= 48 && str[i] <= 57) &&
            (str[i + 1] < 48 || str[i + 1] > 57))
            return ((number * 10 + (str[i] - 48)) * is_neg);
        if (str[i] >= 48 && str[i] <= 57 && str[i] != 45)
            number = number * 10 + (str[i] - 48);
        number = number * is_neg;
        if (number < -2147483648 || number > 2147483647)
            return (0);
        number = number * is_neg;
    }
    return (number * is_neg);
}

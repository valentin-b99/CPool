/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** 
*/
int	my_getnbr(char const *str)
{
    int i = 0;
    int break_while = 0;
    long number = 0;
    int is_neg = 1;

    while (str[i] != '\0' && break_while == 0) {
	if (str[i] == 45) {
	    is_neg = is_neg * (-1);
	} else if (str[i] >= 48 && str[i] <= 57) {
	    number = number * 10 + (str[i] - 48);
	    if (str[i + 1] < 48 || str[i + 1] > 57)
		break_while = 1;
	}
	i = i + 1;
	number = number * is_neg;
	if (number < -2147483648 || number > 2147483647)
	    return (0);
	number = number * is_neg;
    }
    return (number * is_neg);
}

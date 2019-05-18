/*
** EPITECH PROJECT, 2018
** my_print_digits
** File description:
** 
*/

void	my_putchar(char);

int	my_print_digits(void)
{
    int i;

    i = 48;
    while (i <= 57)
    {
	my_putchar(i);
	i = i + 1;
    }
    return (0);
}

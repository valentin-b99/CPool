/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** 
*/

void	my_putchar(char);

int	my_print_alpha(void)
{
    int i;

    i = 97;
    while (i <= 122) {
	my_putchar(i);
	i = i + 1;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** 
*/

void	my_putchar(char);

int	my_print_revalpha(void)
{
    int i;

    i = 122;
    while (i >= 97) {
        my_putchar(i);
        i = i - 1;
    }
    return (0);
}

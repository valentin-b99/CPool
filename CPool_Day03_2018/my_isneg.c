/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** 
*/

void	my_putchar(char);

int	my_isneg(int n)
{
    if (n < 0) {
	my_putchar('N');
    } else {
	my_putchar('P');
    }
    return (0);
}

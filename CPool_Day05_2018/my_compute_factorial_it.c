/*
** EPITECH PROJECT, 2018
** my_compute_factorial_it
** File description:
** 
*/

int	my_compute_factorial_it(int nb)
{
    int result;

    result = nb;
    if (nb < 0 || nb > 12) {
	return (0);
    } else if (nb == 0) {
	return (1);	
    }
    while (nb > 1) {
	result = result * (nb - 1);
	nb = nb - 1;
    }
    return (result);
}

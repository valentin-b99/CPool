/*
** EPITECH PROJECT, 2018
** my_compute_power_it
** File description:
** 
*/

int	my_compute_power_it(int nb, int p)
{
    int result;
    
    result = 1;
    if (p < 0) {
	return (0);
    }
    while (p >= 1) {
	result = result * nb;
	p = p - 1;
    }
    return (result);
}

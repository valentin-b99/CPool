/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** 
*/

int	my_is_prime2(int nb)
{
    int i = 3;
    
    if ((nb % 2 == 0 && nb != 2) || nb == 1)
	return (0);
    while (i * i <= nb) {
	if (nb % i == 0)
	    return (0);
	i = i + 1;
    }
    return (1);
}

int	my_find_prime_sup(int nb)
{
    if (nb < 0)
	nb = 0;
    while (my_is_prime2(nb) == 0) {
	my_is_prime2(nb + 1);
	nb = nb + 1;
    }
    return (nb);
}

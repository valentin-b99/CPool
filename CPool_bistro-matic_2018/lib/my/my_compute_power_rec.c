/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0) {
        return (0);
    } else if (p == 0) {
        return (1);
    } else {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    return (result);
}

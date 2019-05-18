/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** 
*/
#include <unistd.h>

void	my_putchar(char);

void	my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
** EPITECH PROJECT, 2018
** my_print_params
** File description:
** 
*/
#include <unistd.h>

void    my_putchar(char);

int    my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    my_putchar('\n');
    return (0);
}

int    main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
        my_putstr(argv[i]);
    return (0);
}

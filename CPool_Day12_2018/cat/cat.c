/*
** EPITECH PROJECT, 2018
** cat
** File description:
** 
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int    error(char *name, int error_type)
{
    my_putstr("cat: ");
    my_putstr(name);
    if (error_type == 2)
        my_putstr(": No such file or directory\n");
    if (error_type == 21)
        my_putstr(": Is a directory\n");
    return (84);
}

int    read_files(int ac, char **av)
{
    int file;
    char buffer[30000];

    for (int i = 1; i < ac; i++) {
        file = open(av[i], O_RDONLY);
        if (errno != 0)
            return (error(av[i], errno));
        read(file, buffer, 30000);
        if (errno != 0)
            return (error(av[i], errno));
        my_putstr(buffer);
        my_putchar('\n');
    }
    close(file);
    return (0);
}

int    main(int ac, char **av)
{
    int file;
    char buffer[30000];
    
    if (ac == 1) {    
        while ((file = read(0, buffer, 30000)) > 0)
            my_putstr(buffer);
    }
    else
        return (read_files(ac, av));
    return (0);
}

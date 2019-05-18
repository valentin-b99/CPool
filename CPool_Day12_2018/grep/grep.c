/*
** EPITECH PROJECT, 2018
** grep
** File description:
** 
*/

#include "../include/my.h"
//#include <sys/type.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int    error(char *name, int error_type)
{
    my_putstr("grep: ");
    my_putstr(name);
    if (error_type == 2)
        my_putstr(": No such file or directory\n");
    if (error_type == 21)
        my_putstr(": Is a directory\n");
    if (error_type == 901)
	my_putstr("Utilisation: grep <word> [file]\n");
    if (error_type == 902)
	my_putstr(": The read of size 1 is forbidden...\n");
    return (84);
}

int    search_word(char **av)
{
    int file;
    char buffer[30000];
    char buffer_line[30000];
    int i = 0;
    int j = 0;
    int k = 0;

    file = open(av[2], O_RDONLY);
    if (errno != 0)
        return (error(av[2], errno));
    read(file, buffer, 30000);
    if (errno != 0)
        return (error(av[2], errno));
    while (buffer[i] != '\0') {
	while (buffer[i] == av[1][j]) {
	    j++;
	    i++;
	}
	if (buffer[i] != '\n') {
	    buffer_line[k] = buffer[i];
	    k++;
	} else {
	    for (int m = 0; buffer_line[m] != 0; m++)
		buffer_line[m] = 0;
	    k = 0;
	}
	if (j == my_strlen(av[1])) {
	    my_putstr(buffer_line);
	    my_putchar('\n');
	    j = 0;
	} else
	    j = 0;
	i++;
    }
    return (0);
}

int    main(int ac, char **av)
{
    if (ac == 1)
	return (error("\0", 901));
    if (my_strlen(av[1]) < 2)
	return (error(av[1], 902));
    if (ac == 2)
	my_putstr("In dev...");
    if (ac == 3)
	return (search_word(av));
    return (0);
}

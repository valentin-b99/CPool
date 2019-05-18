/*
** EPITECH PROJECT, 2018
** tree
** File description:
** 
*/
#include <unistd.h>

void	my_putchar(char);

int	total_end_line(int size_y)
{
    int i = 6;
    int war = 0;
    int result = 1;

    while (size_y > 0) {
	war = war + 1;
	result = result + i;
	size_y = size_y - 1;
	if (war % 2 == 0) {
	    i = i + 2;
	}
    }
    return (result);
}

int	get_stars(int size_y, int line_choose)
{
    int stars_return = 0;
    int nbr_rtn_star_branch = 0;
    int get_line = 5;
    int return_star_branch = 1;
    int height = 4;
    int line = 1;

    for (line; line <= line_choose; line++) {
	if (nbr_rtn_star_branch == 2) {
	    nbr_rtn_star_branch = 0;
	    return_star_branch = return_star_branch + 1;
	}
	if (line == get_line) {
	    height = height + 1;
	    get_line = get_line + height;
	    stars_return = stars_return - return_star_branch;
	    nbr_rtn_star_branch = nbr_rtn_star_branch + 1;
	} else
	    stars_return = stars_return + 1;
    }
    return (stars_return);
}

void	display_leaves(int size_y, int half_stars)
{
    int spaces = (total_end_line(size_y) / 2 + 1) - half_stars;
    int stars = (half_stars * 2) - 1;
    int isp = 0;
    int ist = 0;

    for (isp; isp < spaces; isp++) {
	my_putchar(' ');
    }
    for (ist; ist < stars; ist++) {
	my_putchar('*');
    }
}

void	display_log(int size_y)
{
    int width = size_y;
    int spaces;
    int ih = 0;
    int iw = 0;
    int is = 0;

    if (size_y % 2 == 0)
	width = size_y + 1;
    spaces = (total_end_line(size_y) / 2 + 1) - ((width / 2) + 1);
    for (ih; ih < size_y; ih++) {
	for (is; is < spaces; is++) {
	    my_putchar(' ');
	}
	is = 0;
	for (iw; iw < width; iw++) {
	    my_putchar('|');
	}
	iw = 0;
	my_putchar('\n');
    }
}

void	tree(int size)
{
    int lines_tot = (((size + 3) * (size + 4)) / 2) - 6;
    int i = 1;

    for (i; i <= lines_tot; i++) {
	display_leaves(size, get_stars(size, i));
	my_putchar('\n');
    }
    display_log(size);
}

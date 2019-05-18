/*
** EPITECH PROJECT, 2018
** my_print_comb
** File description:
** 
*/

void	my_putchar(char);

void	display_putchar(int i1, int i2, int i3)
{
    if (i1 == 55 && i2 == 56 && i3 == 57) {
	my_putchar (i1);
	my_putchar (i2);
	my_putchar (i3);
    } else {
	my_putchar (i1);
	my_putchar (i2);
	my_putchar (i3);
	my_putchar (',');
	my_putchar (' ');
    }
}

void	set_number(int *i1, int *i2, int *i3)
{
    *i1 = 48;
    *i2 = 49;
    *i3 = 50;
}

int	my_print_comb(void)
{
    int i1;
    int i2;
    int i3;

    set_number(&i1, &i2, &i3);
    while (i3 <= 57) {
	display_putchar(i1, i2, i3);
	if (i3 == 57) {
	    i2 = i2 + 1;
	    i3 = i2 + 1;
	} else {
	    i3 = i3 + 1;
	}
	if (i2 == 57) {
	    i1 = i1 + 1;
	    i2 = i1 + 1;
	    i3 = i2 + 1;
	}
    }
    return (0);
}

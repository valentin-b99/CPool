/*
** EPITECH PROJECT, 2018
** my_print_comb2
** File description:
** 
*/

void	my_putchar(char);

void	display_putchar2(int i1, int i2, int i3, int i4)
{
    if (i1 == 57 && i2 == 56 && i3 == 57 && i4 == 57) {
	my_putchar(i1);
        my_putchar(i2);
        my_putchar(' ');
        my_putchar(i3);
        my_putchar(i4);
    } else if ((((i3 * 10) + i4) > ((i1 * 10) + i2)) && i4 <= 57){
	my_putchar(i1);
	my_putchar(i2);
	my_putchar(' ');
	my_putchar(i3);
	my_putchar(i4);
	my_putchar(',');
	my_putchar(' ');
    }
}

void	if_i3(int *i3, int *i2, int *i4)
{
    if (*i3 > 57) {
	*i3 = 48;
	*i2 = *i2 + 1;
	*i4 = *i2 + 1;
    }
}

void	if_i2(int *i1, int *i2, int *i3, int *i4)
{
    if (*i2 > 57) {
	*i1 = *i1 + 1;
	*i2 = 48;
	*i3 = *i2;
	*i4 = *i2 + 1;
    }
}

int	my_print_comb2(void)
{
    int i1 = 48;
    int i2 = 48;
    int i3 = 48;
    int i4 = 49;

    while (i1 <= 57) {
	display_putchar2(i1, i2, i3, i4);
	i4 = i4 + 1;
	if (i4 > 57) {
	    i4 = 48;
	    i3 = i3 + 1;
	}
	if_i3(&i3, &i2, &i4);
	if_i2(&i1, &i2, &i3, &i4);
    }
    return (0);
}

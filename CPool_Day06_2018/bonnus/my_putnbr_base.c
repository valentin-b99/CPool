/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** 
*/
int    convert_binary(int nbr)
{
    int result = 0;

    while (nbr % 2 >= 2) {
	result = (nbr - ((nbr % 2) * 2)) + result * 10;
	nbr = nbr % 2;
    }
    result = (nbr - ((nbr % 2) * 2)) + result * 10;
    return (result);
}

int    my_putnbr_base(int nbr, char const *base)
{
    if (base == "binary") {
	return (convert_binary(nbr));
    }
}

int main(void)
{
    printf("%d\n", my_putnbr_base(256, "binary"));
    return (0);
}

/*
** EPITECH PROJECT, 2018
** my_evil_str
** File description:
** 
*/

int	my_strlen2(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
	i = i + 1;
    }
    return (i);
}

char	*my_evil_str(char *str)
{
    char char_temp;
    int first_char;
    int last_char;
    
    last_char = my_strlen2(str) - 1;
    first_char = 0;
    while (first_char < last_char) {
	char_temp = str[first_char];
	str[first_char] = str[last_char];
	str[last_char] = char_temp;
	first_char = first_char + 1;
	last_char = last_char - 1;
    }
    return (str);
}

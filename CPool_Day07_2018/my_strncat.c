/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** 
*/
int    my_strlen2(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char    *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = my_strlen2(dest);

    while (src[i] != '\0' && i < nb) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}

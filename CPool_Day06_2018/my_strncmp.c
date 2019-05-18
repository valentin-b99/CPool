/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** 
*/
int    my_strlen3(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int    my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int score = 0;

    if (my_strlen3(s1) <= n && my_strlen3(s2) <= n &&
	my_strlen3(s1) > my_strlen3(s2))
        return ((my_strlen3(s1)) - n - (my_strlen3(s2) - n));
    else if (my_strlen3(s1) <= n && my_strlen3(s2) <= n &&
	     my_strlen3(s1) - n < my_strlen3(s2) - n)
        return ((my_strlen3(s1) - n) - (my_strlen3(s2) - n));
    for (i; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] < s2[i])
            score = score - 1;
        else if (s1[i] > s2[i])
            score = score + 1;
    }
    return (score);
}

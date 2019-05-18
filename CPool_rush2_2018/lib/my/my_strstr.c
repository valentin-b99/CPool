/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** 
*/
char    *my_strstr(char *str, char const *to_find)
{
    int i_str = 0;
    int i_fd = 0;
    int to_find_len = my_strlen(to_find);
    int break_while = 0;

    while (str[i_str] != '\0' && break_while == 0) {
        if (str[i_str] == to_find[i_fd] && i_fd == to_find_len - 1)
            return (to_find);
        else if (str[i_str] == to_find[i_fd] && i_fd < to_find_len)
            i_fd = i_fd + 1;
        else
            i_fd = 0;
        i_str = i_str + 1;
    }
    return ("");
}
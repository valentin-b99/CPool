/*
** EPITECH PROJECT, 2018
** rush 3
** File description:
** rush3
*/

#include <unistd.h>
#include "include/my.h"
#include "include/rush3.h"

void display_particular(int, int);
void display(int, int, int);

int test_rush_particular(char *str)
{
    int rush;
    int i = 0;

    while (str[i] != '\n')
        i++;
    if (str[i - 1] == 'A')
        rush = 3;
    else if (str[my_strlen(str) - 2] == 'C')
        rush = 4;
    else
        rush = 5;
    return (rush);
}

int test_rush(char *str, int col_x, int col_y)
{
    int rush;

    if (str[0] == 'o')
        rush = 1;
    if (str[0] == '/' || str[0] == '*')
        rush = 2;
    if (str[0] == 'A')
        rush = test_rush_particular(str);
    else if (str[0] == 'B') {
        display_particular(col_x, col_y);
        return (0);
    }
    display(rush, col_x, col_y);
    return (0);
}

int rush3(char *str)
{
    int col_x = 0;
    int col_y = 0;

    for (int i = 0; str[i] != '\n'; i++)
        col_x++;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            col_y++;
    if (col_y > 2048 && str[0] == 'o') {
        write(2, "none\n", 6);
        return (0);
    } else if (col_y > 2048) {
        test_rush(str, col_x, 2048);
        return (0);
    } else if ((col_x * col_y) > 4095) {
        write(2, "none\n", 6);
        return (0);
    }
    test_rush(str, col_x, col_y);
    return (0);
}

int main(void)
{
    int len;
    char buff[BUFF_SIZE];
    int offset = 0;

    while ((len = read(0 , buff + offset , BUFF_SIZE - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (my_strlen(buff) < 1) {
        write(2, "none\n", 6);
        return (0);
    }
    return (rush3(buff));
}
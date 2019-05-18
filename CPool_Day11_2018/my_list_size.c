/*
** EPITECH PROJECT, 2018
** my_list_size
** File description:
** 
*/

#include "include/my.h"
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;
    struct linked_list_t *list;

    tmp = list;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

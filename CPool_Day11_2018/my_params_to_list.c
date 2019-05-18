/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** 
*/
#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    linked_list_t *element;

    list = NULL;
    element = malloc(sizeof(linked_list_t*));
    for (int i = 0; i < ac; i++) {
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return (list);
}

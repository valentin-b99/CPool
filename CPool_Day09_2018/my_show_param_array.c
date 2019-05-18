/*
** EPITECH PROJECT, 2018
** my_show_param_array
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

struct     info_param {
    int length;
    char *str;
    char *copy;
    char **word_array;
};

struct info_param    *my_params_to_array(int ac, char **av)
{
    struct info_param *result;
    int i = 0;

    result = malloc(sizeof(struct info_param) * ac);
    while (i < ac) {
        result[i].length = my_strlen(av[i]);
        result[i].str = av[i];
        result[i].copy = my_strdup(av[i]);
        result[i].word_array = my_str_to_word_array(concat_params(ac, av));
        i++;
    }
    return (result);
}

int    my_show_param_array(struct info_param const *par)
{
    /*my_put_nbr(par[0].length);
    my_putstr(par[0].str);
    my_putstr(par[0].word_array[0]);*/
    int j = 0;
    
    for (int i = 0; i < (my_arraylen(par) / 4); i++) {
	my_putstr(par[i].str);
	my_putchar('\n');
	my_put_nbr(par[i].length);
	my_putchar('\n');
	//printf("|%d|\n", count_words(par[i].str));
        /*for (int j = 0; j < count_words(par[i].str); j++) {
	    my_putstr(par[i].word_array[j]);
	    my_putchar('\n');
	    }*/
	while (j != j + count_words(par[i].str)) {
	    my_putstr(par[i].word_array[j]);
	    j++;
	}
	//my_show_word_array(par[i].word_array);
	//my_putchar('\n');
	printf("%s\n", "=============");
    }
    //my_putstr(par[0].word_array[2]);
    return (0);
}

int    main(int ac, char **av)
{
    my_show_param_array(my_params_to_array(ac, av));
    return (0);
}

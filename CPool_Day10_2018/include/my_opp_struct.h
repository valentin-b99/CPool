/*
** EPITECH PROJECT, 2018
** my_opp_struct
** File description:
** 
*/

void    my_add(int nb1, int nb2);
void    my_sub(int nb1, int nb2);
void    my_div(int nb1, int nb2);
void    my_mul(int nb1, int nb2);
void    my_mod(int nb1, int nb2);
void    my_usage(void);

struct	operator
{
  char	*operator;
  void	(*function)(int, int);
};

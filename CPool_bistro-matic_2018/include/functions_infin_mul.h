/*
** EPITECH PROJECT, 2018
** functions_infin_mul
** File description:
** functions_infin_mul
*/

struct mul_inputs
{
    char *nb1;
    char *nb2;
    char *base;
    char *opes;
    int neg;
};

struct calc_mul
{
    int curr_nb;
    int carr_nbr;
    char *first_add;
    char *last_add;
    int cnt_decate;
};

char *add_neg(struct mul_inputs, char *);
struct calc_mul refresh_first_add(struct calc_mul, struct mul_inputs);
struct calc_mul calc_mul_next(struct calc_mul, struct mul_inputs, int, int);
char *calculate_mul(struct mul_inputs);
char *mul(struct mul_inputs);
char *main_infin_mul(struct mul_inputs);
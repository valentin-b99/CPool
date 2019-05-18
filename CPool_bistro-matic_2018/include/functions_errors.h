/*
** EPITECH PROJECT, 2018
** functions errors
** File description:
** functions_errors
*/

int test_sim_char_in_str(char const *);
void test_errors_syntax(int, char **);
char *get_expr(int const);
int test_sim_char_btw_str(char const, char const *);
void test_errors_expr(char const *, char **);
int count_par(char const *, char const *);
char *fix_expr(char *, char const *);

#define TESTSICH(chars, i, j) if (chars[i] == chars[j] && i != j) {return (1);}
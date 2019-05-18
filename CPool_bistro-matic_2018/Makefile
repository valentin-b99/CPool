##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= calc

CC	= gcc

RM	= rm -f

SRC	= ./errors/main_errors.c \
	  ./errors/tests_errors.c \
	  ./eval_expr/eval_expr.c \
	  ./eval_expr/eval_expr_2.c \
	  ./eval_expr/eval_expr_3.c \
	  ./eval_expr/operators.c \
	  ./infin_add/infin_add.c \
	  ./infin_add/infin_add2.c \
	  ./infin_mul/infin_mul.c \
	  ./infin_mul/infin_mul2.c \
	  ./main.c \
	  ./main_functions.c 

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy

all: $(NAME)

$(NAME):
	cd lib/my && make re
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
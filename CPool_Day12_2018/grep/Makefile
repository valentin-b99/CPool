##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

NAME	= grep

CC	= gcc

RM	= rm -f

SRC	= grep.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ../lib/my/ -lmy

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

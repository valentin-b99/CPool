##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= libmy.a

CC	= gcc

RM	= rm -f

SRC	= $(shell find . -type f -name '*.c')

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	 $(CC) -c $(SRC)
	 ar rc $(NAME) $(OBJ)
	 make clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

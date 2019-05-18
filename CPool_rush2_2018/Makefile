##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

NAME	= rush2

CC	= gcc

RM	= rm -f

SRC	= *.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy

LIBNAME	= libmy.a

all: $(NAME)

makelibmy:
	cd lib/my && $(CC) -c $(SRC) && ar rc $(LIBNAME) $(OBJ) && $(RM) $(OBJ)

$(NAME):
	make makelibmy
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

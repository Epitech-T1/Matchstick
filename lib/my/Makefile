##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC =	my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \
		my_strlen.c \
		my_getnbr.c \

OBJ = 	$(SRC:.c=.o)

NAME = 	libmy.a

all: 	$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp libmy.a ../

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm ../libmy.a

re: fclean all
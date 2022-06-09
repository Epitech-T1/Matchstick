##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC =	src/main.c \
		src/matchstick.c \
		src/map.c \
		src/error_handling.c \
		src/ia.c \
		src/utilities.c \

OBJ = 	$(SRC:.c=.o)

NAME = 	matchstick

LIB = lib/my/

INCLUDE = include/

CFLAGS = -g

all: 	$(NAME)

$(NAME): 	$(OBJ)
		make -C lib/my
		gcc -g -o $(NAME) $(OBJ) -L$(LIB) -I$(INCLUDE) -lmy -lncurses

clean:
		rm -f $(OBJ)
		make clean -C $(LIB)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re
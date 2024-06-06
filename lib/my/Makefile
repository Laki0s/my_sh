##
## EPITECH PROJECT, 2023
## OwO
## File description:
## UwU
##

SRC	=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv libmy.a ../../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

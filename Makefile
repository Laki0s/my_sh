##
## EPITECH PROJECT, 2024
## B-PSU-200-NCY-2-1-minishell2-quentin.gehin
## File description:
## Makefile
##

SRC        =     src/main.c              	\
            	src/copy_env.c            		\
            	src/set_env.c            		\
            	src/unset_env.c            		\
            src/agrument.c            		\
            src/cd.c                		\
            src/recherche.c            		\
            src/caca.c             	   		\

OBJ        =    $(SRC:.c=.o)
NAME    =    mysh

CC        =    gcc
CFLAGS    =    -I ./include/ -Wextra -Wall -W -g
LIBS    =     -L. -lmy

all:        lib_my $(NAME)

$(NAME):    $(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBS)

%.o: %.c
			$(CC) -c $< -o $@ $(CFLAGS)

clean:
			rm -f $(OBJ)
			rm -f *~ */*~
			$(MAKE) -C lib/my clean

fclean:     clean
			rm -f $(NAME)
			rm -f libmy.a
			$(MAKE) -C lib/my fclean

re:        fclean all

lib_my:
			$(MAKE) -C lib/my all

.PHONY:    all clean fclean re lib_my
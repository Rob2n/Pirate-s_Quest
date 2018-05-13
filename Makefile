##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makes
##

SRC	=	src/main.c \
		src/movement.c \
		src/conv_array.c \
		src/my_getnbr.c \
		src/draw_map.c \
		src/movement2.c \
		src/callback.c \
		src/callback2.c \
		src/callback3.c \
		src/callback4.c \
		src/callback5.c \
		src/callback6.c \
		src/callback7.c \
		src/callback8.c \
		src/anim.c \
		src/anim2.c \
		src/anim3.c \
		src/init.c \
		src/init2.c \
		src/init3.c \
		src/init4.c \
		src/draw.c \
		src/draw_2.c \
		src/handle.c \
		src/handle2.c \
		src/handle3.c	\
		src/handle4.c	\
		src/handle5.c	\
		src/handle6.c	\
		src/collide.c	\
		src/collide2.c	\
		src/collide3.c	\
		src/my_strcmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS  =	-W -Wall -Wextra -Werror -I ./include/ -lcsfml-graphics -lcsfml-audio -lcsfml-system -lm -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

my:	fclean $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

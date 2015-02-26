##
## Makefile for Makefile in /home/dulin_m/rendu/MUL_2014_rtv1
##
## Made by maxime dulin
## Login   <dulin_m@epitech.net>
##
## Started on  Tue Feb  4 13:31:15 2014 maxime dulin
## Last update Sat Mar 15 14:40:21 2014 maxime dulin
##

SRC	= rtv1.c \
	calc_gen.c \
	my_color.c \
	my_print.c \
	calc_plan.c \
	calc_cylindre.c \
	calc_cone.c \
	rotation.c \
	derotation.c

CC	= gcc

RM	= rm -f

NAME	= rtv1

CFLAGS	= -W -Wall -Wextra

LDFLAGS	= -L/usr/lib64 -lmlx_x86_64 -L/usr/lib64/X11 -lXext -lX11 -lm -lmy -L./My_lib/

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): libmy $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	make -C ./My_lib/ clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./My_lib/ fclean
	$(RM) $(NAME)

libmy:
	make -C ./My_lib/

libmyre:
	make -C ./My_lib/ re

re: fclean all

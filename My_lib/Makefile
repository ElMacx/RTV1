##
## Makefile for Makefile in /home/dulin_m/PSU_2013_my_printf
## 
## Made by maxime dulin
## Login   <dulin_m@epitech.net>
## 
## Started on  Tue Nov 12 17:32:36 2013 maxime dulin
## Last update Sat Mar 15 14:41:53 2014 maxime dulin
##

CC	= gcc

SRC	= my_printf.c \
	  my_putchar.c \
          my_isneg.c \
          my_putnbr.c \
          my_swap.c \
          my_putstr.c \
          my_strlen.c \
          my_getnbr.c \
          my_sort_int_tab.c \
          my_power_rec.c \
          my_square_root.c \
          my_is_prime.c \
          my_find_prime_sup.c \
          my_strcpy.c \
          my_strncpy.c \
          my_revstr.c \
          my_strstr.c \
          my_strcmp.c \
          my_strncmp.c \
          my_strupcase.c \
          my_strlowcase.c \
          my_strcapitalize.c \
          my_str_isalpha.c \
          my_str_isnum.c \
          my_str_islower.c \
          my_str_isupper.c \
          my_str_isprintable.c \
          my_showstr.c \
          my_showmem.c \
          my_strcat.c \
          my_strncat.c \
          my_strlcat.c

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) *.c~
	@$(RM) Makefile~

fclean: clean
	@$(RM) $(NAME)

re: fclean all

##
## EPITECH PROJECT, 2025
## G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
## File description:
## Makefile
##

NAME = libmy.a

SRC = 	CSFML/create_sprite.c \
		CSFML/create_window.c \
		string/my_strlen.c \
		string/my_strcat.c \
		string/my_strcpy.c \
		string/my_strcmp.c \
		string/my_rev_str.c \
		disp/my_putstr.c \
		disp/my_putnbr.c \
		disp/my_putchar.c \
		array/my_str_to_word_array.c \
		array/my_len_arr.c \
		array/free_array.c \
		file/size_file.c \

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@mv $(NAME) ..

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(NAME)

re: fclean all

##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for wolf3d
##

NAME = wolf3d

SRC = 	src/main.c \
		src/free_data.c \
		src/game.c \
		src/verify_elements.c \
		src/create_map.c \
		src/create_player.c \
		src/change_weapon_to_id.c \
		src/draw_floor_and_ceiling.c \
		src/menu.c \
		src/init_data.c \
		src/give_data.c \
		src/add_map.c \
		src/add_weapon.c \
		src/get_name.c \
		src/wall.c \
		src/calcul.c \
		src/handle_shoot.c \
		src/mini_map.c \
		src/wall_color.c \
		src/handle_change_weapon.c \
		src/create_head.c \
		src/display_head.c \
		src/disp_ammo.c \
		src/check_map_bounds.c \
		src/free_window.c \
		src/settings.c \
		src/video_mode.c \
		src/music.c \
		src/create_settings.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Iinclude -Ilib/my/include

LIBFLAGS = -Llib -lmy

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

LIBPATH = lib/my


.PHONY: all lib clean fclean clib fclib

all: $(NAME)

lib:
	@make -C $(LIBPATH)

$(NAME): $(OBJ) lib
	@gcc $(OBJ) -o $(NAME) $(LIBFLAGS) $(CSFML) $(CFLAGS)

test: $(OBJ) lib
	@gcc -g $(SRC) -o $(NAME) $(LIBFLAGS) $(CSFML) $(CFLAGS)

clib:
	@make clean -C $(LIBPATH)

fclib:
	@make fclean -C $(LIBPATH)

clean: clib
	@rm -f $(OBJ)

fclean: clean fclib
	@rm -f $(NAME)

re: fclean all



SRC_NAME =  srcs/main.c srcs/event.c srcs/event_state.c srcs/event_state_2.c srcs/bresenham.c srcs/display.c srcs/color.c srcs/hud_editor.c srcs/hud_images.c srcs/hud_utils.c srcs/int_tab_editor.c srcs/select_event.c srcs/select_event_bis.c srcs/hud_select_textures.c srcs/hud_select_textures_bis.c srcs/hud_style.c srcs/hud_dark_theme.c srcs/exit_parse.c srcs/exit_parse_function.c srcs/hud_textures_functions.c srcs/hud_textures_functions_bis.c srcs/hud_textures_functions_ter.c srcs/exit_parse_floor.c srcs/exit_parse_wall.c srcs/exit_parse_wall_2.c srcs/exit_parse_base_floor.c

LIBFT = ../libft/libft.a

LIBMLX = ../minilibx_macos/libmlx.a

LIBMLX2 = ../minilibx_macos/libmlx_Linux.a


INC = include/doom_editor.h

NAME = doom_editor

FLAGS_MATH = -Wall -Wextra -Werror -O3 -flto -march=native -ffast-math

FLAGS = -Llibft -Lminilibx_macos -lX11 -lXext -lbsd -lm -lpthread



OBJ = $(SRC_NAME:%.c=%.o)

all : $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	clang $(FLAGS_MATH) -I include/ -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT) $(LIBMLX)

%.o: %.c $(INC)
	clang $(FLAGS_MATH) -I include/ -c $< -o $@

$(LIBFT):
	make -C ../libft/

$(LIBMLX):
	make -C ../minilibx_macos/ 

clean: 
	make clean -C ../libft/
	make clean -C ../minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ../libft/
	rm -rf $(NAME)

re: fclean all



SRC_PATH = srcs/


SRC_NAME =  srcs/main.c

SRC_NAME += srcs/Event/hooks.c \
			srcs/Event/hooks2.c \

SRC_NAME += srcs/Engine/math.c\
			srcs/Engine/math2.c\
			srcs/Engine/math3.c\
            srcs/Engine/projection.c\
			srcs/Engine/projection2.c\
            srcs/Engine/trace.c\
			srcs/Engine/trace2.c\
			srcs/Engine/trace3.c\
            srcs/Engine/map.c\
			srcs/Engine/map2.c\
            srcs/Engine/matrix.c\
			srcs/Engine/multthread.c\
			srcs/Engine/objects.c\
			srcs/Engine/pickups.c\
			srcs/Engine/pickups2.c\
			srcs/Engine/utils_fct.c


SRC_NAME += srcs/Parsing/parsing_poly.c srcs/Parsing/parsing_error.c \
            srcs/Parsing/parsing_list.c srcs/Parsing/parsing_error2.c \
            srcs/Parsing/parsing_other.c srcs/Parsing/parsing_tex.c \
			srcs/Parsing/parsing_sky.c srcs/Parsing/parsing_tex_norm.c \
    
SRC_NAME += srcs/Parsing_obj/parse_obj.c     \
            srcs/Parsing_obj/object_list.c   \
            srcs/Parsing_obj/obj_error.c     \
            srcs/Parsing_obj/parsing_obj.c   \
            srcs/Parsing_obj/sort_dot.c      \
            srcs/Parsing_obj/sort_poly.c     \
            srcs/Parsing_obj/parsing_mtl.c   \
            srcs/Parsing_obj/obj_mlt.c\
			srcs/Parsing_obj/parsing_norm.c\
			srcs/Parsing_obj/parsing_norm2.c\
			srcs/Parsing_obj/rotate.c\
			srcs/Parsing_obj/rotate_norm.c	

SRC_NAME += srcs/hud/check_event.c       \
            srcs/hud/display_hud.c       \
			srcs/hud/print_hud_norm.c    \
            srcs/hud/display_weapon.c    \
            srcs/hud/event.c             \
			srcs/hud/event2.c            \
			srcs/hud/event_hooks.c       \
            srcs/hud/health_bar.c        \
            srcs/hud/hud.c               \
            srcs/hud/init_function.c     \
            srcs/hud/timer.c             \


LIBFT = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a

LIBMLX2= minilibx_macos/libmlx_Linux.a


INC = include/doom.h

NAME = Doom-nukem

FLAGS_MATH = -Wall -Wextra -Werror -O3 -flto -march=native -ffast-math

FLAGS = -Llibft -lft -Lminilibx_macos -lX11 -lXext -lbsd -lm -lmlx -lpthread



OBJ = $(SRC_NAME:%.c=%.o)

all : $(LIBFT) $(LIBMLX) make_editor $(NAME)

$(NAME): $(OBJ)
	clang $(FLAGS_MATH) -I include/ -o $(NAME) $(OBJ) $(FLAGS)

%.o: %.c $(INC)
	clang $(FLAGS_MATH) -I include/ -c $< -o $@

$(LIBFT):
	make -C libft/

$(LIBMLX):
	make -C minilibx_macos/ 

make_editor:
	cd Editor/ && make

clean: 
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	make fclean -C Editor/
	rm -rf $(NAME)

re: fclean all
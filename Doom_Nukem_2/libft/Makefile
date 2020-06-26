# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 12:26:16 by beduroul     #+#   ##    ##    #+#        #
#    Updated: 2020/03/09 19:47:49 by mwaterso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#__________CONFIG__________#

CC			= clang
NAME		= libft.a

FLAGS		= -fPIC -Wall -Werror -Wextra -g -O3 
INCLUDES	= -I ./include/

SRCDIR		= ./src/
BINDIR		= ./obj/

#File
SRC =	ft_atoi.c			ft_strcmp.c			ft_strcpy.c 		\
			ft_strlen.c			ft_strncmp.c		ft_strncpy.c 		\
			ft_memcpy.c			ft_memset.c			ft_bzero.c			\
 	  		ft_memccpy.c		ft_memmove.c		ft_memchr.c			\
 	  		ft_memcmp.c			ft_strdup.c			ft_strcat.c			\
 	 		ft_strncat.c 		ft_strlcat.c		ft_strchr.c			\
 	  		ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		\
 	  		ft_strrchr.c		ft_strstr.c			ft_isascii.c 		\
 	  		ft_isprint.c		ft_toupper.c		ft_tolower.c		\
 	  		ft_putchar.c		ft_putstr.c 		ft_strnstr.c		\
 	  		ft_strclr.c			ft_putnbr.c			ft_putendl.c		\
 	  		ft_striter.c		ft_striteri.c		ft_memdel.c			\
 	  		ft_strnew.c 		ft_memalloc.c		ft_putchar_fd.c		\
 	  		ft_putendl_fd.c		ft_putnbr_fd.c 		ft_putstr_fd.c		\
 	  		ft_strdel.c			ft_strmap.c			ft_strmapi.c 		\
 	 	 	ft_strequ.c			ft_strnequ.c		ft_strsub.c			\
 	 	 	ft_strjoin.c		ft_strtrim.c		ft_strsplit.c		\
 	 	 	ft_itoa.c			ft_lstnew.c			ft_intsize.c		\
 	  		ft_lstdelone.c		ft_lstdel.c			ft_lstadd.c 		\
 	 	 	ft_lstiter.c		ft_lstmap.c			ft_strrev.c			\
 	  		ft_foreach.c		ft_factorial.c		ft_power.c			\
 	  		ft_is_prime.c		ft_swap.c			ft_range.c 			\
 		  	ft_intsize.c 		get_next_line.c		ft_sqrt.c			\
			ft_strcchr.c		ft_putspace.c		ft_avlen.c			\
			ft_color_txt.c		ft_putendl_color.c	rspace.c 			\
			ft_putstr_color.c 	ft_avswap.c 		ft_up_rounded.c		\
			ft_2dstrdel.c		ft_tablen.c			first_word.c		\
			ft_ispace.c			ft_strnchr.c		ft_putstr_hexa.c	\
			ft_putendl_hexa.c	ft_putnbr_hexa.c	ft_atof.c			\
			ft_strjoin2.c


BIN			= $(SRC:.c=.o)

SRCS		= $(addprefix $(SRCDIR), $(SRC))
BINS		= $(addprefix $(BINDIR), $(BIN))

COMPILE		= $(CC) $(FLAGS) $(INCLUDES)

.PHONY: all clean fclean re

#__________COLORS__________#

R			=	\033[0;31m
G			=	\033[32;7m
B			=	\033[0;34m
N			=	\33[0m

#__________RULES__________#

all: $(NAME)

$(NAME): $(BINS)

	@ar rc $(NAME) $^
	@echo "\n\n${B}[LIBRARY \"$(NAME)\" COMPILED]\n"
	@ranlib $(NAME)
	@echo "${B}[LIBRARY \"$(NAME)\" INDEXED]\n"

$(BINDIR)%.o: $(SRCDIR)%.c include/get_next_line.h include/libft.h
	mkdir -p $(BINDIR) || true
	$(COMPILE) -o $@ -c $<

clean:

	@echo "\n${R}[CLEANING $(NAME) BINARIES]\n"
	@rm -f $(BINS)

fclean: clean

	@echo "${R}[REMOVING \"$(NAME)\"]\n"
	@rm -f $(NAME)

re: fclean all
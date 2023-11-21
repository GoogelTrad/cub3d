SRCS = src/main.c\
	   src/cub3d.c\
	   src/parsing_map.c\
	   src/binding.c\
	   src/utils.c\
	   src/get_next_line.c\
	   src/map.c\
	   src/image.c\
	   src/player.c\
	   src/get_next_line_utils.c\
	   src/parsing_map2.c\
	   src/utils2.c\
	   src/colors.c\
	   src/parsing_cub.c\
	   src/parsing_cub2.c\
	   src/parsing_texture.c\
	   src/parsing_cub3.c\
	   src/texture.c\
	   src/init_player.c\
	   src/parsing_map3.c\
	   src/parsing_arg.c\
	   src/map_save.c\

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror 
NAME = cub3d
LLINKS = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
COMPIL_LINUX = -I/usr/include -Imlx_linux

all: $(NAME)

$(NAME): ${LIBFT} $(OBJS)
	gcc $(OBJS) $(LLINKS) ${LIBFT} -o $(NAME)

$(LIBFT):
	make -C libft

clean: 
	rm -rf $(OBJS) $(OBJS_BONUS) ${LIBFT}

fclean: clean 
	rm -rf $(NAME) $(NAME_BONUS) ${LIBFT}

re: fclean all

.PHONY: all clean flcean re

%.o: %.c
	gcc $(FLAGS) $(COMPIL_LINUX) -c $< -o $@
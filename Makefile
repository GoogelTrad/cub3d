SRCS = main.c\
	   cub3d.c\
	   parsing_map.c\
	   binding.c\
	   utils.c\
	   get_next_line.c\


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

.PHONY: all ${NAME} clean flcean re

%.o: %.c
	gcc $(COMPIL_LINUX) -c $< -o $@
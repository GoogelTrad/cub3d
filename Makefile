SRCS = main.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = cub3d
LLINKS = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
COMPIL_LINUX = -I/usr/include -Imlx_linux

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) $(LLINKS) -o $(NAME)

clean: 
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean 
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all ${NAME} clean flcean re

%.o: %.c
	gcc $(COMPIL_LINUX) -c $< -o $@
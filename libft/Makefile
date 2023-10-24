# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haouni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 01:24:36 by haouni            #+#    #+#              #
#    Updated: 2022/11/12 01:25:27 by haouni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =   $(wildcard *.c)
OBJS    =   ${SRCS:.c=.o}
RM      =   rm -f
CFLAGS  =   -Wall -Wextra -Werror
NAME    = libft.a
LIB     = ft
.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:    ${OBJS}
	ar rc ${NAME} ${OBJS}
all:    ${NAME}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all

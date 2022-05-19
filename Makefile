# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: genouf <genouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:52:42 by genouf            #+#    #+#              #
#    Updated: 2022/05/19 12:43:31 by genouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c arg_check.c instructions.c instructions_bis.c add_index.c sort_this.c find_bigger_sorted.c
OBJS = ${SRCS:.c=.o}

NAME = push_swap

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MAKE = make -C libft
LIBA = ./libft/libft.a 
LIB = -Llibft -lft

all: ${NAME}

${LIBA}:
	${MAKE}

${NAME}: ${OBJS} ${LIBA}
	${CC} -o $@  ${OBJS} ${CLAGS} ${LIB}
	
%.o: %.c
		${CC} ${CFLAGS} -c $^

clean:
		${RM} ${OBJS} ${OBJS_BONUS}
		${MAKE} clean

fclean:	clean
		${RM} ${NAME}
		${MAKE} fclean

re:	fclean all

.PHONY: clean fclean
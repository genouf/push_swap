# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: genouf <genouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:52:42 by genouf            #+#    #+#              #
#    Updated: 2022/05/16 20:20:13 by genouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c arg_check.c instructions.c instructions_bis.c remote.c sort_this.c
OBJS = ${SRCS:.c=.o}

NAME = push_swap

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft
LIBA = libft/libft.a 
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

.PHONY: clean fclean ${LIBA}
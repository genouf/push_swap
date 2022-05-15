# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: genouf <genouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:52:42 by genouf            #+#    #+#              #
#    Updated: 2022/05/14 21:54:47 by genouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c arg_check.c instructions.c
OBJS = ${SRCS:.c=.o}

NAME = push_swap

RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MAKE = cd libft && make
LIB = -Llibft -lft

all: ${NAME}

make: 
	${MAKE}

${NAME}: ${OBJS} make
	${CC} -o $@  ${OBJS} ${CLAGS} ${LIB}
	
%.o: %.c
		${CC} ${CFLAGS} -c ${SRCS}

clean:
		${RM} ${OBJS} ${OBJS_BONUS}
		${MAKE} clean

fclean:	clean
		${RM} ${NAME}
		${MAKE} fclean

re:	fclean all

.PHONY: clean fclean make
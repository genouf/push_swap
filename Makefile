# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: genouf <genouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:52:42 by genouf            #+#    #+#              #
#    Updated: 2022/05/23 14:57:57 by genouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c arg_check.c instructions.c instructions_bis.c add_index.c sort_this.c find_bigger_sorted.c sort_this_big.c sort_this_big_do.c sort_this_big_do_bis.c calcul_instruct.c calcul_i_a.c
OBJS = ${SRCS:.c=.o}

NAME = push_swap

RM = rm -f

CC = gcc
CFLAGS = -g

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
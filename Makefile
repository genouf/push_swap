# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: genouf <genouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:52:42 by genouf            #+#    #+#              #
#    Updated: 2022/06/11 19:03:05 by genouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c arg_check.c instructions.c instructions_bis.c add_index.c sort_this.c find_bigger_sorted.c sort_this_big.c sort_this_big_do.c sort_this_big_do_bis.c calcul_instruct.c calcul_i_a.c
OBJS = ${SRCS:.c=.o}
BONUS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c instructions.c instructions_bis.c arg_check.c sort_this.c instructions_bonus.c instructions_bis_bonus.c
OBJS_BONUS = ${BONUS:.c=.o}

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
	${CC} ${CFLAGS} -o $@  ${OBJS} ${LIB}

bonus : checker

checker:	${OBJS_BONUS} ${LIBA}
		${CC} ${CFLAGS} -o checker ${OBJS_BONUS} ${LIB}
	
%.o:	%.c
		${CC} ${CFLAGS} -c $^

clean:
		${RM} ${OBJS} ${OBJS_BONUS}
		${MAKE} clean

fclean:	clean
		${RM} ${NAME} checker
		${MAKE} fclean

re:	fclean 
	make all

.PHONY: clean fclean re all bonus

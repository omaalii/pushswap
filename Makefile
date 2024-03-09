# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 08:02:28 by omaali            #+#    #+#              #
#    Updated: 2024/03/08 16:09:08 by omaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
# -fsanitize=address

SRC = 	src/errors.c	\
			src/init_nodes_a.c	\
			src/init_nodes_b.c	\
			src/lst_utils.c	\
			src/prep_for_push.c	\
			src/init_stack_a.c	\
			src/push_swap.c	\
			src/push.c	\
			src/rotate.c	\
			src/rotate_both.c \
			src/rotate_moves.c \
			src/sort_stacks.c	\
			src/sort_three.c	\
			src/stack_utils.c	\
			src/swap.c	\

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o : %.c		Makefile includes/push_swap.h
					${CC} ${FLAGS} -I ./ -c $< -o $@

$(NAME):	${OBJECTS}
			${CC} ${FLAGS} -o ${NAME} ${OBJECTS}

all: $(NAME)

clean:
		rm -rf $(OBJECTS)
fclean: clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:			all clean fclean re

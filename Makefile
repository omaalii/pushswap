# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 08:02:28 by omaali            #+#    #+#              #
#    Updated: 2024/03/16 05:27:34 by omaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker

FLAGS = -Wall -Wextra -Werror -g

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
			src/swap.c

SRC_BONUS = checker/checker.c	\
		   checker/get_next_line.c	\
		   checker/get_next_line_utils.c

OBJECTS = $(SRC:.c=.o)
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

%.o : %.c Makefile includes/push_swap.h 
	${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJECTS}
		${CC} ${FLAGS} -o ${NAME} $^

$(NAME_CHECKER):  ${OBJECTS} ${OBJECTS_BONUS} checker/checker.h
		${CC} ${FLAGS} ${OBJECTS_BONUS} ${OBJECTS} -o ${NAME_CHECKER} 

all: $(NAME)

bonus: $(NAME_CHECKER)
	#make -C checker
	
clean:
		rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus



NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g

SRC = erros.c	\
			init_nodes_a.c	\
			init_nodes_b.c	\
			lst_utils.c	\
			prep_for_push.c	\
			push_swap.c	\
			push.c	\
			rotate.c	\
			sort_stacks.c	\
			sort_three.c	\
			stack_utils.c	\
			swap.c	\

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o:%.c		Makefile includes/push_swap.h
					${CC} ${FLAGS} -I ./ -c $< -o $@
all: $(NAME)

clean:
		rm -rf $(OBJECTS)
fclean: clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:			all clean fclean re

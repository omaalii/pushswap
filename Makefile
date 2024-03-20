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
LIBA = .push_swap.a
NAME_CHECKER = checker

FLAGS = -Wall -Wextra -Werror -g

SRC = src/errors.c \
      src/init_nodes_a.c \
      src/init_nodes_b.c \
      src/lst_utils.c \
      src/prep_for_push.c \
      src/init_stack_a.c \
      src/push_swap.c \
      src/push.c \
      src/rotate.c \
      src/rotate_both.c \
      src/rotate_moves.c \
      src/sort_stacks.c \
      src/sort_three.c \
      src/stack_utils.c \
      src/swap.c

SRC_BONUS = bonus/checker.c \
            bonus/get_next_line.c \
            bonus/get_next_line_utils.c

OBJECTS = $(SRC:.c=.o)
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc

%.o: %.c Makefile includes/push_swap.h
		${CC} ${FLAGS} -I ./ -c $< -o $@

$(LIBA): $(OBJECTS)
		ar -rcs $@ $(OBJECTS)

$(NAME): $(OBJECTS)
		$(CC) $(FLAGS) -o $(NAME) $^

all: $(NAME)

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJECTS_BONUS) $(LIBA)
		$(CC) $(FLAGS) $(OBJECTS_BONUS) -o $(NAME_CHECKER) $(LIBA)

clean:
		rm -rf $(OBJECTS) $(OBJECTS_BONUS) $(LIBA)

fclean: clean
		rm -rf $(NAME) $(LIBA) $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus



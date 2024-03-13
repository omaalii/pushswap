# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 02:05:40 by omaali            #+#    #+#              #
#    Updated: 2024/03/13 02:13:12 by omaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker

FLAGS = -Wall -Wextra -Werror -g
# -fsanitize=address

SRCBONUS = checker/checker.c	\
		   checeker/get_next_line.c	\
		   checker/get_next_line_utils.c

OBJECTSBONUS = $(SRCBONUS:.c=.o)

CC = gcc

%.o : %.c		Makefile checker.h
				${CC} ${FLAGS} -I -c $< -o $@

$(NAME_CHECKER):	${OBJECTSBONUS}
					${CC} ${FLAGS} -o ${NAME_CHECKER} ${OBJECTSBONUS}

bonus: $(NAME_CHECKER)

clean:
	rm -rf $(OBJECTSBONUS)

fclean: clean
	rm -rf $(NAME_CHECKER)

re:		fclean bonus

.PHONY:	clean fclean re bonus


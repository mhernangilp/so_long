# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 20:16:42 by mhernang          #+#    #+#              #
#    Updated: 2023/03/28 13:48:17 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

CC = gcc

NAME = so_long

SRC = src/main.c \
	  src/check_error.c \
	  src/utils.c \
	  src/read_map.c \
	  src/gnl/get_next_line.c \
	  src/gnl/get_next_line_utils.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

INCLUDE = so_long.h \
		  get_next_line.h

all:	${NAME}

${NAME}: ${OBJ} ${INCLUDE}
	gcc ${OBJ} ${FLAGS} -o ${NAME}


clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclear

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 20:16:42 by mhernang          #+#    #+#              #
#    Updated: 2023/06/21 13:20:42 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

CC = gcc

NAME = so_long

SRC = src/main.c \
	  src/check_error.c \
	  src/check_error_utils1.c \
	  src/check_error_utils2.c \
	  src/utils.c \
	  src/read_map.c \
	  src/gnl/get_next_line.c \
	  src/gnl/get_next_line_utils.c \
	  src/init.c \
	  src/render.c \
	  src/input.c \
	  src/end_game.c \
	  src/open_file.c \
	  src/render_moves.c \
	  src/ft_printf/ft_printf.c \
	  src/ft_printf/tools/ft_itoa.c \
	  src/ft_printf/tools/ret_putchar.c \
	  src/ft_printf/tools/ret_puthex.c \
	  src/ft_printf/tools/ret_putnbr.c \
	  src/ft_printf/tools/ret_putstr.c \
	  src/ft_printf/tools/ret_putuns.c \
	  src/ft_printf/tools/ret_putvoid.c

OBJ = ${SRC:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

INCLUDE = so_long.h \
		  get_next_line.h \
		  ft_printf.h

all:	${NAME}

${NAME}: ${OBJ} ${INCLUDE}
	${CC} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclear

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 20:16:42 by mhernang          #+#    #+#              #
#    Updated: 2023/03/26 20:48:00 by mhernang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX = libmlx.a

SRCS = src/*.c \
	   src/gnl/*.c

CC = clang

CFLAGS = -Wall -Wextra -Werror

$(NAME):
	@ $(MAKE) -C mlx all >/dev/null 2>&1
	@ cp ./mlx/$(MLX) .
	@$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -g -fsanitize=address -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

clean:
	@ $(MAKE) -C mlx clean
	@ rm -rf so_long.dSYM so_long_bonus.dSYM >/dev/null 2>&1

fclean:	clean
	@ rm $(MLX)
	@ rm so_long >/dev/null 2>&1
	@ rm so_long_bonus >/dev/null 2>&1

re:			fclean all

.PHONY:		$(NAME) all bonus test clean fclean re

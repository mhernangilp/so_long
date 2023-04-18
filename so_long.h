/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:55 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/18 20:17:35 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	s_map;

typedef struct pos
{
	int	y;
	int	x;
}	pos;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				s_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	s_map	map;
	s_img	img;
	pos		player;
	int		moves;
	int		total_collec;
	int		collec;
}				s_game;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

int	input(int key, s_game *game);
void	init_game(s_game *game, char **argv);
int	render(s_game *game);
int	check_error(int args, char **argv);
s_map	read_map(char *path);
pos	get_pos(s_map map, char c);
int	check_characters(s_map map);
int	check_player(s_map map);
int	check_exit(s_map map);
int	check_coleccionable(s_map map);
int	check_walls(s_map map);
int	check_path(s_map map);
int	ft_strrncmp(char *s1, char *s2, int n);

#endif

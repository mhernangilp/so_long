/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:55 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/21 13:20:18 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	t_pos	player;
	int		moves;
	int		total_collec;
	int		collec;
}				t_game;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

int		input(int key, t_game *game);
void	init_game(t_game *game, char **argv);
int		render(t_game *game);
void	render_moves(t_game *game);
void	free_map(t_map *map);
int		end_game(t_game *game);
int		check_error(int args, char **argv);
t_map	read_map(char *path);
t_pos	get_pos(t_map map, char c);
int		check_characters(t_map map);
int		check_player(t_map map);
int		check_exit(t_map map);
int		check_coleccionable(t_map map);
int		check_walls(t_map map);
int		check_path(t_map map);
int		ft_strrncmp(char *s1, char *s2, int n);
int		open_file(char *path);

#endif

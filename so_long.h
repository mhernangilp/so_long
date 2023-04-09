/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:55 by mhernang          #+#    #+#             */
/*   Updated: 2023/04/09 19:30:20 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

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

int	check_error(int args, char **argv);
s_map	read_map(char *path);
int	check_characters(s_map map);
int	check_player(s_map map);
int	check_exit(s_map map);
int	check_coleccionable(s_map map);
int	check_walls(s_map map);
int	check_path(s_map map);
int	ft_strrncmp(char *s1, char *s2, unsigned int n);

#endif

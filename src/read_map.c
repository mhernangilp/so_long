/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:50:48 by mhernang          #+#    #+#             */
/*   Updated: 2023/06/21 13:21:07 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	read_new_line(char *temp, int *width,
			int *widthaux, int *height)
{
	if (temp)
	{
		(*width) = ft_strlen(temp);
		if (temp[(*width) - 1] == '\n')
			(*width)--;
		(*widthaux) = (*width);
		(*height)++;
	}
}

static void	getdimensions(char *path, t_map *map)
{
	int		fd;
	char	*temp;
	int		width;
	int		widthaux;
	int		height;

	fd = open_file(path);
	temp = get_next_line(fd);
	width = ft_strlen(temp);
	if (temp[width - 1] == '\n')
		width--;
	widthaux = width;
	height = 1;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		read_new_line(temp, &width, &widthaux, &height);
	}
	close(fd);
	free(temp);
	map -> height = height;
	map -> width = width;
}

static void	set_width(t_map *map, char *temp, int *i)
{
	*i = -1;
	while (++(*i) < map -> width)
	{
		map -> map[0][*i] = temp[*i];
	}
}

static void	write_line(char *temp, int *j, int *i, t_map *map)
{
	*i = -1;
	if (temp)
		while (++*i < map -> width)
			map -> map[*j][*i] = temp[*i];
}

t_map	read_map(char	*path)
{
	int		fd;
	t_map	map;
	char	*temp;
	int		i;
	int		j;

	getdimensions(path, &map);
	map.map = malloc(map.height * sizeof(char *));
	i = -1;
	while (++i < map.height)
		map.map[i] = malloc(map.width * sizeof(char *));
	fd = open_file(path);
	temp = get_next_line(fd);
	set_width(&map, temp, &i);
	j = 0;
	while (++j < map.height)
	{
		free(temp);
		temp = get_next_line(fd);
		write_line(temp, &j, &i, &map);
	}	
	close(fd);
	free(temp);
	return (map);
}

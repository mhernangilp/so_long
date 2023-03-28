/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:50:48 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/28 13:48:09 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_width(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}
static int	get_height(char *map)
{
	int	i;
	int	cont;

	i = -1;
	cont = 0;
	while (map[++i])
		if (map[i] == '\n')
			cont++;
	return (cont);
}

s_map str_to_mtrx(char *map)
{
	struct s_map	matrix;
	int				i;
	int				j;
	int				k;

	matrix.width = get_width(map);
	matrix.height = get_height(map);
	printf("--Mapa antes malloc:\n%sAdress: %p\n", map, &map[0]);
	matrix.map = malloc(matrix.width * sizeof(char *));
	i = -1;
	printf("--Mapa despues malloc:\n%sAdress: %p\n", map, &map[0]);
	while (++i < matrix.width)
		matrix.map[i] = malloc(matrix.height * sizeof(char *));
	i = 0;
	j = 0;
	while (j < matrix.height)
	{
		k = 0;
		while (k < matrix.width)
		{

			printf("Pongo '%c'(ASCII: %d) en [%d][%d] con i: '%d'\n", map[i], (int)map[i], k, j, i);
			matrix.map[k][j] = map[i];
			i++;
			k++;
		}
		j++;
		i++;
	}
	return (matrix);
}

char	*read_map(char	*path)
{
	int		fd;
	char	*map;
	char	*temp1;
	char	*temp2;

	fd = open(path, O_RDONLY);
	temp1 = get_next_line(fd);
	map = ft_strjoin("", temp1);
	while (temp1)
	{
		free(temp1);
		temp1 = get_next_line(fd);
		temp2 = ft_strdup(map);
		free(map);
		if (temp1)
			map = ft_strjoin(temp2, temp1);
		free(temp2);
	}
	close(fd);
	free(temp1);
	return (map);
}

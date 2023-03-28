/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:55 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/28 13:48:14 by mhernang         ###   ########.fr       */
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

int	check_error(int args, char **argv);
char	*read_map(char *path);
s_map	str_to_mtrx(char *map);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strrncmp(char *s1, char *s2, unsigned int n);

#endif

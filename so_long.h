/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:59:55 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/26 19:52:31 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

int	check_error(int args, char **argv);
char	*read_map(char *path);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strrncmp(char *s1, char *s2, unsigned int n);

#endif

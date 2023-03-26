/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:24:54 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/26 20:48:07 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strrncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (i != -1 && j != -1 && n-- > 0)
	{
		if (s1[i--] != s2[j--])
			return (1);
	}
	if (n > 0)
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
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

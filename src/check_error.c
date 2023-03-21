/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:13:35 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/21 19:51:06 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_return(int return_value)
{
	//printea el error depeniendo del valor de vuelta de la funcion check_map
}

int	check_map(char	*map)
{
	//preuba con todos los posibles mapas erroneos y cada error devuelve un error diferente, si todo ok, devuelve 0
}

int	check_error(int args, char **argv)
{
	char	*map;
	int		return_value;

	if (args != 2)
	{
		printf("Error\nInvalid number of arguments");
		return (-1);
	}
	else if (ft_strrncmp(argv[1], ".ber", 4))
	{
		printf("Error\nMap file must be .ber!");
		return (-1);
	}
	map = read_map(argv[1]);
	printf("%s", map);
	return_value = check_map(map);
	if (return_value)
	{
		check_return(return_value);
		return (-1);
	}
	return (return_value);
}

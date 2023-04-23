/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:06:25 by mhernang          #+#    #+#             */
/*   Updated: 2023/03/19 20:48:06 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf.h"

int	ret_putnbr(int n)
{
	int		ret;
	char	*str;

	str = ft_itoa(n);
	ret = ret_putstr(str);
	free(str);
	return (ret);
}

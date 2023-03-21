/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:03:45 by mhernang          #+#    #+#             */
/*   Updated: 2023/02/21 19:27:07 by mhernang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		line_has_n(char *buf);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*return_mem(char *mem, int mode);
char	*ft_strdup(const char *src);
char	*cat_mem_buf(char *mem, char *buf, int read);
char	*ret_out_mem(char *mem);

#endif

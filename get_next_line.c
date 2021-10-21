/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:00:20 by schung            #+#    #+#             */
/*   Updated: 2021/10/20 21:49:01 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*rest_check(char *src)
{
	if (!src)
	{
		src = malloc(sizeof(char) * 1);
		src[0] = '\0';
	}
	return (src);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*dest;
	static char	*rest;
	int			quantity;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	quantity = 1;
	rest = rest_check(rest);
	while (!(ft_strchr(rest, '\n')) && quantity != 0)
	{
		quantity = read(fd, buff, BUFFER_SIZE);
		if (quantity == -1)
		{
			free(rest);
			return (NULL);
		}
		buff[quantity] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	dest = ft_strdup(rest);
	rest = ft_new_rest(rest);
	return (dest);
}

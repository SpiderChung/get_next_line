/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:52:30 by schung            #+#    #+#             */
/*   Updated: 2021/10/21 20:54:37 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
	static char	*rest[256];
	int			quantity;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	quantity = 1;
	rest[fd] = rest_check(rest[fd]);
	while (!(ft_strchr(rest[fd], '\n')) && quantity != 0)
	{
		quantity = read(fd, buff, BUFFER_SIZE);
		if (quantity == -1)
		{
			free(rest[fd]);
			return (NULL);
		}
		buff[quantity] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buff);
	}
	dest = ft_strdup(rest[fd]);
	rest[fd] = ft_new_rest(rest[fd]);
	return (dest);
}

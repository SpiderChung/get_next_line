/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:00:20 by schung            #+#    #+#             */
/*   Updated: 2021/10/15 12:09:39 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char        *buff;
    char        *dest;
    static char *rest;
    int         quantity;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    quantity = 1;
    while (!(ft_strchr(rest, '\n')) && quantity != 0)
    {
        quantity = read(fd, buff, BUFFER_SIZE);
        if (quantity == -1)
        {
            free(buff);
        }
        buff[quantity] = '\0';
        rest = ft_strjoin(rest, buff);
    }
    free(buff);

    return ()
}



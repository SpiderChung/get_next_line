/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:33:00 by schung            #+#    #+#             */
/*   Updated: 2021/10/20 21:30:14 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*r;

	i = 0;
	r = (char *)s;
	while (r[i] != (char)c)
	{
		if (r[i] == '\0')
			return (0);
		i++;
	}
	return (r + i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	len;
	unsigned int	i;
	unsigned int	k;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1);
	len = k + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < k)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		res[i] = *s2++;
		i++;
	}
	res[len] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	if (!(s1[i]))
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	a = (char *)malloc((i + 2) * sizeof(char));
	if (!a)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		a[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_new_rest(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	free(src);
	return (dest);
}

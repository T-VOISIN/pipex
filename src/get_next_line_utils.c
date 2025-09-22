/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:33:25 by niroched          #+#    #+#             */
/*   Updated: 2025/02/06 14:23:04 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	ft_strcpy_gnl(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		src[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_add_n(char *str, int len)
{
	char	*temp;

	temp = malloc (sizeof(char) * (len + 2));
	if (!temp)
	{
		free (str);
		return (NULL);
	}
	ft_strcpy_gnl(temp, str);
	temp[len] = '\n';
	temp[len + 1] = '\0';
	free (str);
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		y;

	if (!s1 || !s2)
		return (NULL);
	dest = ft_calloc ((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof (char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = '\0';
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	len;
	size_t	n;

	if (count == 0 || size == 0)
		return (NULL);
	if (count > ((size_t)-1 / size))
		return (NULL);
	len = count * size;
	dest = (void *) malloc(len);
	if (!dest)
		return (NULL);
	n = 0;
	while (n < len)
	{
		*(char *)(dest + n) = 0;
		n++;
	}
	return (dest);
}

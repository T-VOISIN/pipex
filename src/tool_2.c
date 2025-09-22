/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:23 by tvoisin           #+#    #+#             */
/*   Updated: 2025/02/06 14:22:51 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

char	*ft_strchr(char *str, char c)
{
	int		i;
	int		y;
	char	*dest;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	y = 0;
	dest = malloc(sizeof (char) * (i + 1));
	if (!dest)
		return (free (str), NULL);
	while (y < i)
	{
		dest[y] = str[y];
		y++;
	}
	dest[y] = '\0';
	return (dest);
}

char	*ft_strjoinn(const char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		y;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc (sizeof (char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2 && s2[y])
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = '\0';
	free (s2);
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (*(char *)(s1 + i) != *(char *)(s2 + i))
			break ;
		i++;
	}
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}

void	ft_free(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free (dest);
}

size_t	ft_strlen(const char *str)
{
	int	c;

	if (!str)
		return (-1);
	c = 0;
	while (str[c])
		c++;
	return (c);
}

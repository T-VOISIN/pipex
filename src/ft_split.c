/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:01:30 by tvoisin           #+#    #+#             */
/*   Updated: 2025/02/06 14:23:23 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	*ft_freesplit( char **dest, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

char	*ft_sstrdup(char *src, int min, int max)
{
	int		i;
	char	*dest;

	if (min > max)
		return (0);
	if (!src)
		return (NULL);
	dest = malloc((max - min + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (min < max)
	{
		dest[i] = src[min];
		i++;
		min++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_word(char *str, char c)
{
	int	i;
	int	booleen;
	int	count;

	booleen = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && booleen == 0)
		{
			count++;
			booleen = 1;
		}
		else if (str[i] == c && booleen == 1)
			booleen = 0;
		i++;
	}
	return (count);
}

char	**cpy_split(char **dest, const char *str, char c)
{
	int		index;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str))
			&& index >= 0)
		{
			dest[j++] = ft_sstrdup((char *)str, index, i);
			if (!dest[j - 1])
				return (ft_freesplit(dest, j));
			index = -1;
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *str, char c)
{
	char	**dest;

	if (!str)
		return (NULL);
	dest = malloc ((check_word((char *)str, c) + 1) * sizeof (char *));
	if (!dest)
		return (NULL);
	dest = cpy_split(dest, str, c);
	return (dest);
}

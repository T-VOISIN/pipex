/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:59 by niroched          #+#    #+#             */
/*   Updated: 2025/02/04 18:04:18 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	ft_test_gnl(char *buf, int nb_read, int len)
{
	int	pos_n;

	if (nb_read == -1)
		return (-2);
	if (nb_read == 0 && len == 0)
		return (0);
	pos_n = 0;
	while (buf[pos_n] && buf[pos_n] != '\n')
		pos_n++;
	if (buf[pos_n] != '\n')
		pos_n = -1;
	return (pos_n);
}

static char	*ft_start_gnl(char *buf, int *len, int *pos_n)
{
	char	*temp;

	*len = ft_strlen_gnl(buf);
	*pos_n = -1;
	if (*len == 0)
		return ("");
	temp = malloc (sizeof(char) * (*len + 1));
	if (!temp)
		return (NULL);
	ft_strcpy_gnl(temp, buf);
	*pos_n = 0;
	while (temp[*pos_n] != '\n' && temp[*pos_n])
		(*pos_n)++;
	if (temp[*pos_n] != '\n')
		*pos_n = -1;
	return (temp);
}

static char	*ft_join_gnl(char *buf, int nb_read, char *str, int len)
{
	char	*temp;
	int		size;

	buf[nb_read] = '\0';
	size = nb_read + len + 1;
	if (nb_read == 0)
		return (str);
	temp = malloc (sizeof(char) * size);
	if (!temp)
	{
		if (str != NULL)
			free (str);
		return (NULL);
	}
	ft_strcpy_gnl(temp, str);
	ft_strcpy_gnl(temp + len, buf);
	if (len != 0 && str != NULL)
		free (str);
	return (temp);
}

static char	*ft_subline_gnl(char *str, char *buf, int nb_read, int len)
{
	int	i;

	if (nb_read == 0 && len == 0)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
	{
		ft_strcpy_gnl(buf, str + i + 1);
		str[i + 1] = '\0';
	}
	else if (str[i])
	{
		str = ft_add_n(str, i);
		if (!str)
			return (NULL);
		*buf = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			len;
	int			pos_n;
	int			nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_start_gnl(buf, &len, &pos_n);
	if (!str)
		return (NULL);
	nb_read = BUFFER_SIZE;
	while (pos_n == -1 && nb_read > 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		pos_n = ft_test_gnl(buf, nb_read, len);
		if (pos_n == -2)
			return (NULL);
		str = ft_join_gnl(buf, nb_read, str, len);
		len = len + nb_read;
	}
	return (ft_subline_gnl(str, buf, nb_read, len));
}

// void	ftputstr(char *str)
// {
// 	write(1, str, ft_strlen_gnl(str));
// }

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("1char.txt", O_RDONLY);

// 	if (fd == -1) 
// 		return (1);
// 	while ((line = get_next_line(fd)))
// 	{
// 		ftputstr(line);
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// }
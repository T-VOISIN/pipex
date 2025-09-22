/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:04:10 by tvoisin           #+#    #+#             */
/*   Updated: 2025/02/10 12:16:36 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

char	*give_pwd(char *str, char **env)
{
	char	**start;
	char	*end;
	char	*dest;
	int		i;

	if (!str || str[0] == '\0')
		return (NULL);
	start = find_start(env);
	end = ft_strjoinn("/", ft_strchr(str, ' '));
	i = 0;
	while (start && start[i])
	{
		dest = ft_strjoin(start[i], end);
		if (access(dest, (F_OK || X_OK)) == 0)
		{
			free (end);
			ft_free(start);
			return (dest);
		}
		free(dest);
		i++;
	}
	free(end);
	ft_free(start);
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	return_perror(int i)
{
	if (i == 1)
		perror ("error fork\n");
	if (i == 2)
		perror("error pipe\n");
	return (1);
}

int	error_file(char *str, int i)
{
	int	pipefd[2];

	if (i == 1)
	{
		if (access(str, F_OK) == 0)
			ft_putstr_fd("zsh : access denied", 2);
	}
	if (i == 2)
		ft_putstr_fd("Error Argv\n", 2);
	if (i == 3)
	{
		if (access(str, F_OK) == 0)
			ft_putstr_fd("zsh : access denied: ", 2);
		else
			ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(str, 2);
		write(2, "\n", 1);
		pipe(pipefd);
		close (pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		return (-2);
	}
	return (-1);
}

int	check_argv(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
	{
		if (!av || av[i][0] == 0)
			return (1);
		i++;
	}
	return (0);
}

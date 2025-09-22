/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:09:36 by tvoisin           #+#    #+#             */
/*   Updated: 2025/02/10 11:03:57 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	close_fds(void)
{
	int	fd;

	fd = 3;
	while (fd < 1025)
	{
		close(fd);
		fd++;
	}
}

int	what_open(char *av, int mod)
{
	int	fd_next;

	if (mod == 0)
	{
		fd_next = open (av, O_RDONLY, 0777);
		if (fd_next == -1)
			return (error_file(av, 3));
	}
	if (mod == 1)
		fd_next = open (av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (mod == 2)
		fd_next = open (av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd_next == -1)
		return (error_file(av, 1));
	return (fd_next);
}

void	exec_cmd(char *av, char **env)
{
	char	**split;
	char	*cmd;

	split = ft_split(av, ' ');
	cmd = give_pwd(av, env);
	if (execve(cmd, split, env) == -1)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		if (split[0] != NULL)
			ft_putstr_fd(split[0], 2);
		write (2, "\n", 1);
		ft_free(split);
		exit (127);
	}
	free(cmd);
	ft_free(split);
	exit (1);
}

void	read_here_doc(int *pipefd, char **av)
{
	char	*set;

	close (pipefd[0]);
	while (1)
	{
		set = get_next_line(0);
		if (ft_strncmp(set, av[2], ft_strlen(av[2])) == 0
			&& set[ft_strlen(av[2])] == '\n')
		{
			free (set);
			get_next_line(-1);
			close (pipefd[1]);
			exit (1);
		}
		ft_putstr_fd(set, pipefd[1]);
		free(set);
	}
}

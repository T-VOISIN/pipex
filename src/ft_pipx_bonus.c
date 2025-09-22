/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipx_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:58:15 by tvoisin           #+#    #+#             */
/*   Updated: 2025/02/10 12:14:26 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

/*
pipefd 
1 = write
0 = read

dup2 (oldfd, newfd);
0=stdin
1= stdout 

*/

int	one_pipe(char *av, char **env)
{
	pid_t	pid;
	int		newpipe[2];

	if (pipe(newpipe) == -1)
		return (return_perror(2));
	pid = fork();
	if (pid == -1)
		return (return_perror(1));
	if (pid == 0)
	{
		close(newpipe[0]);
		dup2(newpipe[1], 1);
		close (newpipe[1]);
		exec_cmd(av, env);
	}
	else
	{
		close (newpipe[1]);
		dup2(newpipe[0], 0);
		close (newpipe[0]);
	}
	return (0);
}

int	here_doc(char **av, char **env)
{
	pid_t	pid;
	int		newpipe[2];

	(void)env;
	if (pipe(newpipe) == -1)
		return (return_perror(2));
	pid = fork();
	if (pid == -1)
		return (return_perror(1));
	if (pid == 0)
	{
		close (1);
		read_here_doc(newpipe, av);
		close (0);
	}
	else
	{
		close (newpipe[1]);
		dup2 (newpipe[0], 0);
		close (newpipe[0]);
		wait (NULL);
	}
	return (0);
}

int	last_exec(char **av, char **env, int fd, int ac)
{
	pid_t	pid;
	int		a;

	pid = fork();
	if (pid == -1)
		return (return_perror(1));
	if (pid == 0)
		exec_cmd(av[ac - 2], env);
	else
	{
		close (fd);
		waitpid (pid, &a, 0);
		if (fd == -1)
			return (1);
		return (WEXITSTATUS(a));
	}
	return (0);
}

int	start(int ac, char **av, char **env)
{
	int	fd_next;
	int	fd_final;
	int	i;

	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0 && ac > 5)
	{
		here_doc(av, env);
		fd_final = what_open(av[ac - 1], 2);
		i = 3;
	}
	else
	{
		fd_next = what_open(av[1], 0);
		fd_final = what_open(av[ac - 1], 1);
		dup2(fd_next, 0);
		close (fd_next);
		i = 2;
	}
	while (i < ac - 2)
	{
		one_pipe(av[i], env);
		i++;
	}
	return (fd_final);
}

int	main(int ac, char **av, char **env)
{
	int	fd_final;

	if (ac < 5 || check_argv(av) == 1)
		return (error_file(NULL, 2));
	fd_final = start (ac, av, env);
	dup2(fd_final, 1);
	ac = last_exec(av, env, fd_final, ac);
	close_fds();
	return (ac);
}

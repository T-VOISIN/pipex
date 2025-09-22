/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:58:28 by tvoisin           #+#    #+#             */
/*   Updated: 2025/02/06 14:33:56 by tvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/wait.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* PIPEX */

int		what_open(char *av, int mod);
int		one_pipe(char *av, char **env);
void	exec_cmd(char *av, char **env);
void	read_here_doc(int *pipefd, char **av);
int		here_doc(char **av, char **env);
int		last_exec(char **av, char **env, int fd, int ac);

/* TOOL */

char	*ft_strchr(char *str, char c);
char	*give_pwd(char *str, char **env);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		error_file(char *str, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(char **dest);
int		check_argv(char **av);
char	*ft_strjoinn(const char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		return_perror(int i);
void	close_fds(void);
char	**find_start(char **env);

/* SPLIT */
void	*ft_freesplit( char **dest, size_t len);
char	*ft_sstrdup(char *src, int min, int max);
int		check_word(char *str, char c);
char	**cpy_split(char **dest, const char *str, char c);
char	**ft_split(char const *str, char c);

/* GNL */
int		ft_strcpy_gnl(char *dest, char *src);
int		ft_strlen_gnl(char *str);
char	*ft_add_n(char *str, int len);
char	*get_next_line(int fd);
int		ft_test_gnl(char *buf, int nb_read, int len);
void	*ft_calloc(size_t count, size_t size);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:37:57 by rmicheli          #+#    #+#             */
/*   Updated: 2021/12/07 12:50:42 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIP_H
# define PIP_H

# include <errno.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int			pair[2];
	int			fd[2][2];
	pid_t		pid;
	char		**path;

}				t_pip;

int				put_usage(const int errnum);
char			**get_path(char **env);
char			**get_cmd_arr(char cmd[], char **env);
char			**path_search(char *av, char *env[]);
int				ft_error(const int errnum);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *p);
void			ft_free_str_arr(char ***arr);

#endif
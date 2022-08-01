/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:28:08 by rmicheli          #+#    #+#             */
/*   Updated: 2021/12/07 12:54:39 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pip.h"

int	ft_error(const int errnum)
{
	if (errnum == 0)
	{
		ft_putstr_fd("ERROR: ", 1);
		ft_putstr_fd(strerror(errno), 1);
		ft_putstr_fd("\n", 1);
	}
	if (errnum == 1)
		ft_putstr_fd("ERROR: Too less arguments\n", 1);
	if (errnum == 2)
		ft_putstr_fd("ERROR: Cannot find binary of the given command\n", 1);
	if (errnum == 3)
		ft_putstr_fd("ERROR: ft_strjoin fail\n", 1);
	exit(1);
	return (1);
}

char	**get_cmd_arr(char cmd[], char **env)
{
	char	**cmd_arr;

	cmd_arr = NULL;
	cmd_arr = path_search(cmd, env);
	return (cmd_arr);
}

static	void	closer(t_pip *p)
{
	if (close(p->fd[0][0]) == -1)
		ft_error(0);
	if (close(p->fd[0][1]) == -1)
		ft_error(0);
	if (close(p->fd[1][0]) == -1)
		ft_error(0);
	if (close(p->fd[1][1]) == -1)
		ft_error(0);
	while (wait(NULL) > 0)
		;
}

void	cmd(t_pip *p, int i, char **av, char **env)
{
	static char			**cmd_arr;

	cmd_arr = get_cmd_arr(av[2 + i], env);
	p->pid = fork();
	if (p->pid == -1)
		ft_error(0);
	if (p->pid == 0)
	{
		if (dup2(p->fd[i][0], 0) == -1)
			ft_error(0);
		if (dup2(p->fd[i][1], 1) == -1)
			ft_error(0);
		if (close(p->fd[!(i)][0]) == -1)
			ft_error(0);
		if (close(p->fd[!(i)][1]) == -1)
			ft_error(0);
		if (execve(cmd_arr[0], cmd_arr, env) == -1)
			ft_error(0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pip			p;

	if (ac != 5)
		ft_error(1);
	if (pipe(p.pair) == -1)
		ft_error(0);
	p.fd[0][0] = open(av[1], O_RDONLY);
	p.fd[0][1] = p.pair[1];
	p.fd[1][0] = p.pair[0];
	p.fd[1][1] = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (p.fd[0][0] == -1 || p.fd[1][1] == -1)
		ft_error(0);
	cmd(&p, 0, av, env);
	cmd(&p, 1, av, env);
	closer(&p);
	return (0);
}

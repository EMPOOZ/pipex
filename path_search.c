/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:48:36 by tconwy            #+#    #+#             */
/*   Updated: 2021/12/07 12:50:41 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pip.h"

#define PATH    "PATH="

static char	**path_search_make_argv(char *av)
{
	char	**program;
	char	*tmp;

	program = NULL;
	tmp = NULL;
	program = ft_split(av, ' ');
	if (!program)
		ft_error(0);
	tmp = ft_strjoin("/", program[0]);
	if (!tmp)
		ft_error(0);
	free(program[0]);
	program[0] = tmp;
	return (program);
}

static char	**path_search_extra(char *av, char **splited_path)
{
	int		i;
	char	*tmp;
	char	**program;

	i = 0;
	tmp = NULL;
	program = path_search_make_argv(av);
	while (splited_path[i])
	{
		tmp = ft_strjoin(splited_path[i], program[0]);
		if (!tmp)
			ft_error(0);
		if (access(tmp, F_OK) == 0)
		{
			free(program[0]);
			program[0] = tmp;
			return (program);
		}
		free(tmp);
		i++;
	}
	ft_free_str_arr(&program);
	return (NULL);
}

static void	search1(char ***splited_av, char *av)
{
	*splited_av = ft_split(av, ' ');
	if (!*splited_av)
		ft_error(0);
}

static void	search(char ***splited_av, char *av, char *env[])
{
	int		i;
	char	**splited_path;

	i = 0;
	splited_path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], PATH, sizeof(PATH) - 1))
		{
			splited_path = ft_split(env[i] + sizeof(PATH) - 1, ':');
			if (!splited_path)
			{
				ft_error(0);
			}
			*splited_av = path_search_extra(av, splited_path);
			break ;
		}
		i++;
	}
	if (splited_path)
		ft_free_str_arr(&splited_path);
}

char	**path_search(char *av, char *env[])
{
	char	**splited_av;

	splited_av = NULL;
	if (!*av)
		return (NULL);
	if (ft_strchr(av, '/'))
		search1(&splited_av, av);
	else
		search(&splited_av, av, env);
	return (splited_av);
}

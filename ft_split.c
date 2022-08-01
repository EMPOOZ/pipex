/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:00:14 by tconwy            #+#    #+#             */
/*   Updated: 2021/12/07 12:50:35 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pip.h"

void	free_string(char **u)
{
	int	y;

	y = 0;
	while (u[y])
		free(u[y++]);
	free(u);
}

int	mas(char const *g, int c)
{
	size_t	t;
	size_t	n;
	char	*y;

	y = (char *)g;
	t = 0;
	n = 0;
	while (*y != '\0')
	{
		if (n == 0 && *y != c && *y != '\0')
		{
			t++;
			n = 1;
		}
		else if (n == 1 && *y == c)
			n = 0;
		y++;
	}
	return (t);
}

void	ft_split2(char const *s, char c, char **split)
{
	size_t	m;
	size_t	df;

	m = 0;
	while (*s)
	{
		if (*s != c)
		{
			df = 0;
			while (*s && *s != c && ++df)
				s++;
			split[m] = ft_substr(s - df, 0, df);
			if (!split[m++])
				free_string(split);
		}
		else
			s++;
	}
	split[m] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = malloc((mas(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_split2(s, c, split);
	return (split);
}

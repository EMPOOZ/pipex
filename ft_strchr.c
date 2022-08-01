/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:00:20 by tconwy            #+#    #+#             */
/*   Updated: 2021/12/07 12:50:36 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pip.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	g;

	g = 0;
	while (s[g] != (unsigned char)c)
	{
		if (!s[g])
			return (0);
		++g;
	}
	return ((char *)&s[g]);
}

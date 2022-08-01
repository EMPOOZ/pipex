/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:51:02 by rmicheli          #+#    #+#             */
/*   Updated: 2021/12/07 12:50:39 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pip.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*t;
	size_t		c;
	size_t		i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen((char *)s) < len)
		len = ft_strlen((char *)s);
	t = (char *)malloc(sizeof(*s) * (len + 1));
	if (!t)
		return (0);
	c = 0;
	i = 0;
	while (s[c])
	{
		if (c == start)
			while (s[c] && len-- > 0)
				t[i++] = s[c++];
		c++;
		if (i > 0)
			break ;
	}
	t[i] = '\0';
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:35:28 by rmicheli          #+#    #+#             */
/*   Updated: 2021/12/07 12:50:38 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pip.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	c;
	size_t	m;

	c = 0;
	if (!haystack || !needle)
		return (NULL);
	while (haystack[c] && c < n)
	{
		m = 0;
		while (haystack[c + m] && needle[m]
			&& (c + m < n) && (haystack[c + m] == needle[m]))
			m++;
		if (!needle[m])
			return ((char *)(haystack + c));
		c++;
	}
	return (NULL);
}

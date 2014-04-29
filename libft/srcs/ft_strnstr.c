/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:58:03 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/07 12:29:53 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (*s2 == '\0')
	{
		return ((char *)s1);
	}
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[0])
		{
			y = 1;
			while (s1[i + y] == s2[y] && (i + y) < n)
			{
				y++;
			}
			if (s2[y] == '\0')
			{
				return ((char *)&(s1[i]));
			}
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:19:04 by fbeck             #+#    #+#             */
/*   Updated: 2013/11/26 11:05:23 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	UCHAR	*ptr;

	i = 0;
	ptr = (UCHAR *)str;
	while (n > i)
	{
		if (ptr[i] == (UCHAR)c)
		{
			return (&(ptr[i]));
		}
		i++;
	}
	return (NULL);
}

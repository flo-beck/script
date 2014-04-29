/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:14:37 by fbeck             #+#    #+#             */
/*   Updated: 2013/11/26 11:25:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	n;
	size_t	res;

	n = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (dlen >= size)
	{
		return (size + slen);
	}
	res = dlen + slen;
	while (src[n] != '\0' && dlen < (size - 1))
	{
		dest[dlen] = src[n];
		dlen++;
		n++;
	}
	dest[dlen] = '\0';
	return (res);
}

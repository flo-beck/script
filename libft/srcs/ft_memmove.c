/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:23:11 by fbeck             #+#    #+#             */
/*   Updated: 2013/11/26 11:07:23 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cpysrc;

	i = 0;
	cpysrc = (char *)malloc(n * sizeof(char));
	ft_memcpy(cpysrc, src, n);
	ft_memcpy(dest, cpysrc, n);
	free (cpysrc);
	return (dest);
}

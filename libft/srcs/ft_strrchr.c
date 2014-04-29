/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:43:38 by fbeck             #+#    #+#             */
/*   Updated: 2013/11/26 11:43:09 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		if (str[i - 1] == (char)c)
		{
			return ((char *)&(str[i - 1]));
		}
		i--;
	}
	return (NULL);
}
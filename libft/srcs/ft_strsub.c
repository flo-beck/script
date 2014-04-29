/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:26:04 by fbeck             #+#    #+#             */
/*   Updated: 2013/12/11 15:43:12 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	UINT	i;

	res = NULL;
	if (s)
	{
		i = 0;
		res = (char *)malloc((len + 1) * sizeof(char));
		if (res)
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}

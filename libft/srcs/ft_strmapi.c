/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:21:31 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:53:41 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	UINT	i;

	res = NULL;
	if (s && f)
	{
		i = 0;
		res = (char *)malloc((ft_strlen(s)) * sizeof(char) + 1);
		if (!res)
			return (NULL);
		while (s[i] != '\0')
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

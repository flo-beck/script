/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:19:10 by fbeck             #+#    #+#             */
/*   Updated: 2013/12/11 15:40:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:28:58 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:54:07 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	size_t	i;

	cpy = NULL;
	if (s)
	{
		i = 0;
		cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (cpy)
		{
			while (ft_isspace(*s))
				s++;
			while (s[i] != '\0')
			{
				cpy[i] = s[i];
				i++;
			}
			i--;
			while (ft_isspace((UCHAR)cpy[i]))
				i--;
			cpy[i + 1] = '\0';
		}
	}
	return (cpy);
}

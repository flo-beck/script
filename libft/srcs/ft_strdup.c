/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:56:43 by fbeck             #+#    #+#             */
/*   Updated: 2014/02/12 16:16:02 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;
	size_t	n;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	cpy = (char *)malloc((i + 1) * sizeof(char));
	if (cpy)
	{
		n = 0;
		while (str[n] != '\0')
		{
			cpy[n] = str[n];
			n++;
		}
		cpy[n] = '\0';
	}
	return (cpy);
}

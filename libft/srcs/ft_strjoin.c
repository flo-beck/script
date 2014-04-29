/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:27:35 by fbeck             #+#    #+#             */
/*   Updated: 2013/12/12 18:46:32 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	res = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s1 || s2)
	{
		res = ft_strnew(len1 + len2 + 1);
		if (!res)
			return (NULL);
		if (s1)
		{
			ft_strcpy(res, s1);
			ft_strcat(res, s2);
		}
		else
			ft_strcpy(res, s2);
	}
	return (res);
}

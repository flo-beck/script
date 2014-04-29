/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:34:39 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:53:56 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;
	UCHAR	*str1;
	UCHAR	*str2;

	i = 0;
	str1 = (UCHAR *)s1;
	str2 = (UCHAR *)s2;
	while (i < n && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	if (i == n)
		res = 0;
	else
		res = (str1[i] - str2[i]);
	return (res);
}

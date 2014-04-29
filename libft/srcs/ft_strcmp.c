/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:51:03 by fbeck             #+#    #+#             */
/*   Updated: 2014/02/05 12:08:38 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		res;
	UCHAR	*str1;
	UCHAR	*str2;

	i = 0;
	str1 = (UCHAR *)s1;
	str2 = (UCHAR *)s2;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	res = (str1[i] - str2[i]);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 12:43:36 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/21 11:12:37 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_indexof(char *str, char c)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}

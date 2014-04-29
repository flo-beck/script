/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:15:48 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/25 11:54:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		res;

	if (str == NULL)
		return (0);
	res = 0;
	while (ft_isblank(*str) == 1)
	{
		str = str + 1;
	}
	i = ((*str == '+' || *str == '-') ? 1 : 0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[0] == '-')
	{
		res = -res;
	}
	return (res);
}

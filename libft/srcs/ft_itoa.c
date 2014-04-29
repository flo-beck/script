/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:31:36 by fbeck             #+#    #+#             */
/*   Updated: 2014/02/23 20:20:38 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_numdig(int n)
{
	size_t		i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	else
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
		return (i);
	}
}

static void		ft_fillstr(char *str, int n, size_t pos, int sign)
{
	str[pos] = '\0';
	pos--;
	if (n == 0)
	{
		str[pos] = '0';
	}
	else
	{
		while (n > 0)
		{
			str[pos] = (n % 10) + '0';
			n = n / 10;
			pos--;
		}
		if (sign < 0)
		{
			str[pos] = '-';
		}
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			sign;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	sign = n;
	if (sign < 0)
	{
		n = -n;
	}
	len = ((sign < 0) ? 1 : 0) + ft_numdig(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		ft_fillstr(str, n, len, sign);
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:35:38 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/26 20:37:51 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_free_split(char ***info)
{
	int		i;

	i = 0;
	if (*info)
	{
		while ((*info)[i])
		{
			ft_strdel(&(*info)[i]);
			i++;
		}
		free(*info);
		*info = NULL;
	}
}

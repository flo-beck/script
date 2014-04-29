/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 14:18:12 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/04 23:18:40 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_strs(char **tbl, int n)
{
	int		i;
	int		ordered;

	ordered = FALSE;
	while (ordered == FALSE)
	{
		ordered = TRUE;
		i = 0;
		while (i < (n - 1))
		{
			if (ft_strcmp(tbl[i], tbl[i + 1]) > 0)
			{
				ft_swap_ptr((void **)&(tbl[i]), (void **)&(tbl[i + 1]));
				ordered = FALSE;
			}
			i++;
		}
		n--;
	}
}

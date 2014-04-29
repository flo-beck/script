/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:28:40 by fbeck             #+#    #+#             */
/*   Updated: 2014/02/21 18:53:16 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_lst(t_list *list, int (*ft_test_elem)(t_list *e1, t_list *e2))
{
	t_list	*ptr;
	int		ordered;

	ptr = list;
	ordered = FALSE;
	while (ordered == FALSE)
	{
		ordered = TRUE;
		ptr = list;
		while (ptr && ptr->next)
		{
			if (ft_test_elem(ptr, ptr->next) == 1)
			{
				ft_swap_lst(ptr, ptr->next);
				ordered = FALSE;
			}
			ptr = ptr->next;
		}
	}
}

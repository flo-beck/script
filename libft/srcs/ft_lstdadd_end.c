/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 17:34:48 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:51:30 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that adds an element at the end of a doubly linked list when given
** a whole elem
*/
void		ft_lstdadd_end(t_listd **alst, t_listd *elem)
{
	t_listd	*ptr;

	ptr = *alst;
	if (ptr)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = elem;
		elem->prev = ptr;
	}
	else
		*alst = elem;
}

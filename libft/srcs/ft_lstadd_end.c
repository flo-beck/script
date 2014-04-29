/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 11:48:23 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:51:07 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that adds an element at the end of a list when given a whole elem
*/
void	ft_lstadd_end(t_list **alst, t_list *elem)
{
	t_list	*ptr;

	ptr = *alst;
	if (ptr)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = elem;
	}
	else
		*alst = elem;
}

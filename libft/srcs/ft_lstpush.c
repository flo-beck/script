/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 16:53:03 by fbeck             #+#    #+#             */
/*   Updated: 2013/12/30 15:30:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that adds a new element at the END of a list from content and size
** -returns a pointer to the head of the list
*/
t_list		*ft_lstpush(t_list **alst, void *content, size_t content_size)
{
	t_list	*ptr;

	ptr = *alst;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_lstnew(content, content_size);
	}
	else
		*alst = ft_lstnew(content, content_size);
	return (*alst);
}

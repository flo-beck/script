/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:10:19 by fbeck             #+#    #+#             */
/*   Updated: 2013/12/01 19:15:35 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = NULL;
	if (lst)
	{
		tmp = f(lst);
		newlst = ft_lstnew(tmp->content, tmp->content_size);
		newlst->next = ft_lstmap(lst->next, f);
	}
	return (newlst);
}

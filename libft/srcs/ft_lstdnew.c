/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 17:31:49 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:52:18 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_listd		*ft_lstdnew(void const *content, size_t content_size)
{
	t_listd	*new;

	new = (t_listd *)malloc(sizeof(t_listd));
	if (new)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content_size = content_size;
			new->content = (void *)malloc(content_size);
			if (new->content)
				ft_memcpy(new->content, content, content_size);
		}
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

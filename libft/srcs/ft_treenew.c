/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:34:10 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/30 13:18:34 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_tree		*ft_treenew(void *data, size_t data_size)
{
	t_tree	*new;

	if (!(new = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	if (!data)
	{
		new->data = NULL;
		new->data_size = 0;
	}
	else
	{
		new->data = (void *)malloc(data_size);
		if (new->data)
			ft_memcpy(new->data, data, data_size);
		new->data_size = data_size;
	}
	return (new);
}

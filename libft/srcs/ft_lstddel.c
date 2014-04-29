/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstddel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 17:40:44 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:51:46 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstddel(t_listd **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		ft_lstddel(&((*alst)->next), del);
		ft_lstddelone(alst, del);
	}
}

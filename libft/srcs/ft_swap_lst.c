/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:13:46 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/07 12:31:48 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_swap_lst(t_list *s1, t_list *s2)
{
	void		*tmp_content;
	size_t		tmp_size;

	tmp_content = s1->content;
	tmp_size = s1->content_size;
	s1->content = s2->content;
	s1->content_size = s2->content_size;
	s2->content = tmp_content;
	s2->content_size = tmp_size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 19:48:12 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/03 21:41:31 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "script.h"
#include "libft.h"

int			ft_open_file(t_env *e)
{
	char	*path;

	path = (e->filename ? e->filename : "typescript");
	if (e->op.a)
		e->fd_file = open(path, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		e->fd_file = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (e->fd_file < 0)
	{
		ft_putstr_fd("Failed to open file ", 2);
		ft_putendl_fd(path, 2);
		return (-1);
	}
	return (0);
}

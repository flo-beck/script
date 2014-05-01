/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 19:48:12 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 10:58:48 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "script.h"

int			ft_open_file(t_env *e)
{
	char	*path;

	path = (e->filename ? e->filename : "typescript");
	if (e->op.a)
		e->fd_file = open(path, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		e->fd_file = open(path, O_WRONLY | O_CREAT, 0666);
	if (e->fd_file < 0)
	{
		printf("Failed to open file %s\n", path);
		return (-1);
	}
	return (0);
}

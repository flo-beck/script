/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 20:15:07 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 10:53:39 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "script.h"

static t_ops	ft_read_options(t_ops op, char *av)
{
	int			i;

	i = 1;
	while (av[i] != '\0' && !op.err)
	{
		if (av[i] == 'a')
			op.a = 1;
		else if (av[i] == 'q')
			op.q = 1;
		else
		{
			ft_op_err(av[i]);
			op.err = 1;
		}
		i++;
	}
	return (op);
}

int			ft_parse_args(t_env *e, int ac)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac && !e->index_cmd)
		{
			if (e->av[i][0] == '-')
			{
				e->op = ft_read_options(e->op, e->av[i]);
				if (e->op.err)
					return (0);
			}
			else if (!e->filename)
				e->filename = e->av[i];
			else
				e->index_cmd = i;
			i++;
		}
	}
	return (1);
}

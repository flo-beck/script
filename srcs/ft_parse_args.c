/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 20:15:07 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/29 20:25:29 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "script.h"

static t_ops	ft_read_options(t_ops ops, char *av)
{
	int			i;

	i = 1;
	while (av[i] != '\0' && !ops.err)
	{
		if (av[i] == 'a')
			ops.op_a = 1;
		else if (av[i] == 'q')
			ops.op_q = 1;
		else
		{
			ft_op_err(av[i]);
			ops.err = 1;
		}
		i++;
	}
	return (ops);
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
				e->ops = ft_read_options(e->ops, e->av[i]);
				if (e->ops.err)
					return (0);
			}
			else if (!e->index_filename)
				e->index_filename = i;
			else
				e->index_cmd = i;
			i++;
		}
	}
	return (1);
}

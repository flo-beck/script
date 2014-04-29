/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:33:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/29 20:24:45 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "script.h"

static void		ft_init_env(t_env *e, char **av)
{
	e->index_cmd = 0;
	e->index_filename = 0;
	e->ops.op_a = 0;
	e->ops.op_q = 0;
	e->ops.err = 0;
	e->av = av;
}

int				main(int ac, char **av)
{
	t_env		e;

	ft_init_env(&e, av);
	if (!ft_parse_args(&e, ac))
		return (0);
	printf("OPTIONS! -a %d -q %d \n", e.ops.op_a, e.ops.op_q);
	if (e.index_filename)
		printf("filename %s \n", av[e.index_filename]);
	else
		printf("filename typescript\n");
	if (e.index_cmd)
		printf("CMD : %s\n", av[e.index_cmd]);

	return (0);
}

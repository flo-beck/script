/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:33:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/02 12:02:54 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "script.h"

void			ft_get_shell(t_env *e, char **envp)
{
	int			i;

	i = 0;
	e->envp = envp;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "SHELL=", 6))
			e->shell= &envp[i][6];
		i++;
	}
}

t_env			*ft_get_env(void)
{
	static t_env	env;
	return (&env);
}

static void		ft_init_env(t_env *e, char **av)
{
	e->index_cmd = 0;
	e->filename = NULL;
	e->op.a = 0;
	e->op.q = 0;
	e->op.err = 0;
	e->av = av;
	e->pid_zombie = 0;
}

int				main(int ac, char **av, char **envp)
{
	t_env		*e;

	e = ft_get_env();
	ft_init_env(e, av);
	if (!ft_parse_args(e, ac))
		return (0);
	e->shell = "/bin/sh";
	ft_get_shell(e, envp);
/*	printf("SHELL IS %s\n",e->shell );
	printf("OPTIONS! -a %d -q %d \n", e->op.a, e->op.q);
	if (e->filename)
		printf("filename %s \n", e->filename);
	else
		printf("filename typescript\n");
	if (e->index_cmd)
		printf("CMD : %s\n", av[e->index_cmd]);*/

	if (ft_open_file(e) < 0)
		return (0);
	ft_script(e);

	//printf("END\n");

	return (0);
}

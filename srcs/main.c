/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:33:15 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/03 21:36:48 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "script.h"

t_env				*ft_get_env(void)
{
	static t_env	env;

	return (&env);
}

static void			ft_get_shell(t_env *e, char **envp)
{
	int				i;

	i = 0;
	e->envp = envp;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "SHELL=", 6))
			e->shell = &envp[i][6];
		i++;
	}
}

static void			ft_init_env(t_env *e, char **av, char **envp)
{
	e->index_cmd = 0;
	e->filename = NULL;
	e->op.a = 0;
	e->op.q = 0;
	e->op.err = 0;
	e->av = av;
	e->envp = envp;
	e->pid_zombie = 0;
}

int					main(int ac, char **av, char **envp)
{
	t_env			*e;

	e = ft_get_env();
	ft_init_env(e, av, envp);
	if (!ft_parse_args(e, ac))
		return (0);
	e->shell = "/bin/sh";
	ft_get_shell(e, envp);
	if (ft_open_file(e) < 0)
		return (0);
	ft_script(e);
	return (0);
}

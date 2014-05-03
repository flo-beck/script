/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 11:05:12 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/03 21:44:23 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "script.h"

void		ft_add_cmd(char *path, int j, t_env *e)
{
	int		n;
	char	*cmd;

	n = 0;
	if (j < P_SIZE)
	{
		cmd = e->av[e->index_cmd];
		path[j++] = '/';
		while (cmd[n] != '\0' && j < P_SIZE)
			path[j++] = cmd[n++];
	}
}

int			ft_get_path(char path[P_SIZE], t_env *e)
{
	int		i;
	int		n;
	int		j;

	i = 0;
	while (e->envp[i] && (ft_strncmp("PATH=", e->envp[i], 5)))
		i++;
	n = 5;
	while (e->envp[i] && e->envp[i][n])
	{
		ft_bzero(path, P_SIZE);
		j = 0;
		while (e->envp[i][n] != '\0' && e->envp[i][n] != ':' && j < P_SIZE)
			path[j++] = e->envp[i][n++];
		ft_add_cmd(path, j, e);
		if (e->envp[i][n])
			n++;
		if ((access(path, X_OK)) == 0)
			return (1);
	}
	return (0);
}

void		ft_exec_shell(t_env *e, int fd_slave)
{
	char	*cmd[3];
	char	path[P_SIZE];

	(void)fd_slave;
	if (e->index_cmd)
	{
		if (e->av[e->index_cmd][0] == '/')
			execve(e->av[e->index_cmd], &e->av[e->index_cmd], e->envp);
		else if (ft_get_path(path, e))
			execve(path, &e->av[e->index_cmd], e->envp);
	}
	else
	{
		cmd[0] = e->shell;
		cmd[1] = "-i";
		cmd[2] = NULL;
		execve(e->shell, cmd, e->envp);
	}
	ft_putendl_fd("ft_script: Command not found", 2);
}

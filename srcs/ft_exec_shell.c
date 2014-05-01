/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 11:05:12 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 18:47:44 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "script.h"

void		ft_exec_shell(t_env *e, int fd_slave)
{
	char	*cmd[3];

	(void)fd_slave;
	/*if (e->index_cmd)
	{
		//EXEC THIS CMD
	}
	else //EXEC SHELL IN INTERACTIVE MODE (-i)
	{*/
		cmd[0] = e->shell;
		cmd[1] = "-i";
		cmd[2] = NULL;
		execve(e->shell, cmd, e->envp);
	/*}*/
	ft_putendl_fd("Command not found", 2);
	_exit(1);
}

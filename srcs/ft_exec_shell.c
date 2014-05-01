/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 11:05:12 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 13:41:28 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "script.h"

void		ft_exec_shell(t_env *e, int fd_slave)
{
	char	*const* cmd;


	ft_bzero(cmd[0], 128);
	ft_bzero(cmd[1], 128);
	cmd[2] = NULL;

	(void)fd_slave;
	
	/*if (e->index_cmd)
	{
		//EXEC THIS CMD
	}
	else //EXEC SHELL IN INTERACTIVE MODE (-i)
	{*/
//		cmd[0] = e->shell;
//		cmd[1] = "-i";
//		cmd[2] = NULL;
		execve(e->shell, cmd, e->envp);
	/*}*/
	ft_putendl_fd("Command not found", 2);
	_exit(1);
}

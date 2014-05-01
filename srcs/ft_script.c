/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 12:17:14 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 22:22:29 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/wait.h>

#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include "script.h"

void			ft_put_head(int fd)
{
	struct timeval	tp;
	struct timezone	tzp;

	if (-1 == (gettimeofday(&tp, &tzp)))
		write(fd, "Can't get no tiiiiiiime", 23);
	else
	{
		write(fd, "Script started on ", 18);
		write(fd, ctime(&tp.tv_sec), 25);
	}
}

void			ft_script(t_env *e)
{
	int			fd_master;
	int			fd_slave;
	static char	ptynamebuf[128];	/* ioctl knows length */
	int			pid;

	signal(SIGCHLD, ft_sigchild);
	if (ft_get_pty(ptynamebuf, &fd_master))
		printf("Could not open free PTY pair!\n");

	if ((fd_slave = open(ptynamebuf, O_RDWR)) < 0) // OPEN SLAVE
	{
		printf("FAILED TO OPEN SLAVE\n");
		return ;
	}
	e->fd_master = fd_master;
	e->fd_slave = fd_slave;

	go_raw(0);
	if ((pid = fork()) == -1)
	{
		//PROBLEMO
	}

	if (!pid) // CHILD PROCESS
	{
		printf("CHILD1\n");
		if (!e->op.q)
			ft_put_head(e->fd_file);
		dup2(fd_slave, 0);
		dup2(fd_slave, 1);
		dup2(fd_slave, 2);
		close(e->fd_file);
		ft_exec_shell(e, fd_slave);
		/*close(e->fd_file);
		  close(fd_master);
		  close(fd_slave);*/
//		reset_terminal(0);
	}
	else // PARENT PROCESS
	{
		ft_manage_input_output(e, pid);
/*		ft_close_all(e);
		close(e->fd_file);
		close(fd_master);
		close(fd_slave);
		reset_terminal(0);*/
	}
}

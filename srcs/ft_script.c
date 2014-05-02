/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 12:17:14 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/02 17:51:28 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/wait.h>

#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include "libft.h"
#include "script.h"

void			ft_put_head(t_env *e, int fd)
{
	struct timeval	tp;
	struct timezone	tzp;

	if (-1 == (gettimeofday(&tp, &tzp)))
		write(fd, "Can't get no tiiiiiiime", 23);
	else
	{
		write(fd, "Script started on ", 18);
		write(fd, ctime(&tp.tv_sec), 25);
		write(1, "Script started, output file is ", 31);
		if (e->filename)
			ft_putendl_fd(e->filename, 1);
		else
			ft_putendl_fd("typescript", 1);
	}
}

void			ft_script(t_env *e)
{
	int			fd_master;
	int			fd_slave;
	static char	ptynamebuf[128];	/* ioctl knows length */
	int			pid;

	signal(SIGCHLD, ft_sigchild);
	if (((ft_get_pty(ptynamebuf, &fd_master)) < 0)
			|| ((fd_slave = open(ptynamebuf, O_RDWR)) < 0 ))
	{
		ft_putendl("Could not open a free PTY");
		return ;
	}
	e->fd_master = fd_master;
	e->fd_slave = fd_slave;

	go_raw(0);
	if ((pid = fork()) == -1)
	{
		ft_putendl("Error: failed to properly fork");
		return ;
	}

	if (!pid) // CHILD PROCESS
	{
		if (!e->op.q)
			ft_put_head(e, e->fd_file);
		close(e->fd_file);
		if ((setsid() == -1) || (ioctl(e->fd_slave, TIOCSCTTY, NULL) == -1))
		{
			ft_putendl("Error: Could not modify controlling TTY");
			return ;
		}
		dup2(fd_slave, 0);
		dup2(fd_slave, 1);
		dup2(fd_slave, 2);
		close(e->fd_slave);
		ft_exec_shell(e, fd_slave);
	}
	else // PARENT PROCESS
	{
		ft_manage_input_output(e, pid);
	}
}

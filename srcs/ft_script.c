/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 12:17:14 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/03 21:36:03 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "script.h"

void				ft_put_head(t_env *e, int fd)
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

static void			ft_setup_tty_and_shell(t_env *e)
{
	close(e->fd_master);
	if (!e->op.q)
		ft_put_head(e, e->fd_file);
	close(e->fd_file);
	if ((setsid() == -1) || (ioctl(e->fd_slave, TIOCSCTTY, NULL) == -1))
	{
		ft_putendl("Error: Could not modify controlling TTY");
		return ;
	}
	dup2(e->fd_slave, 0);
	dup2(e->fd_slave, 1);
	dup2(e->fd_slave, 2);
	close(e->fd_slave);
	ft_exec_shell(e, e->fd_slave);
}

void				ft_script(t_env *e)
{
	static char		ptynamebuf[128];
	int				pid;

	ft_signal(SIGCHLD, ft_sigchild);
	if (((ft_get_pty(ptynamebuf, &e->fd_master)) < 0)
			|| ((e->fd_slave = open(ptynamebuf, O_RDWR)) < 0))
	{
		ft_putendl("Could not open a free PTY");
		return ;
	}
	go_raw(0, e);
	if ((pid = fork()) == -1)
	{
		ft_putendl("Error: failed to properly fork");
		return ;
	}
	if (!pid)
		ft_setup_tty_and_shell(e);
	else
		ft_manage_input_output(e, pid);
}

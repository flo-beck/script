/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 22:17:56 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 22:18:14 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include "script.h"
#include "libft.h"

void				ft_close_all(t_env *e)
{
	close(e->fd_file);
	close(e->fd_master);
	close(e->fd_slave);
}

static void			ft_put_foot(t_env *e, int fd)
{
	struct timeval	tp;
	struct timezone	tzp;

	if (-1 == (gettimeofday(&tp, &tzp)))
		ft_putendl_fd("Can't get no tiiiiiiime", fd);
	else
	{
		ft_putstr_fd("Script done on ", fd);
		ft_putendl_fd(ctime(&tp.tv_sec), fd);
		ft_putstr_fd("Script done, output file is ", 1);
		ft_putendl_fd(e->filename, 1);
	}
}

void				ft_shutdown(t_env *e, int pid)
{
	if (pid)
		kill(pid, SIGUSR1);
	if (!e->op.q)
	{
		ft_put_foot(e, e->fd_file);
	}
	close(e->fd_file);
	_exit(1);
}

void				ft_close(int whatisthis)
{
	t_env 			*e;

	(void)whatisthis;
	e = ft_get_env();
	close(e->fd_file);
	_exit(-1);
}

void				ft_sigchild(int qqc)
{
	t_env			*e;

	(void)qqc;
	e = ft_get_env();
	if (!e->op.q)
		write(1, "\n", 1);
	if (e->pid_zombie)
		ft_shutdown(e, e->pid_zombie);
	else
		ft_shutdown(e, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 19:13:56 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/03 21:31:04 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "script.h"

static void				ft_resize(int sig)
{
	struct winsize		ws;
	t_env				*e;

	(void)sig;
	e = ft_get_env();
	if (ioctl(0, TIOCGWINSZ, &ws) != -1)
		ioctl(e->fd_master, TIOCSWINSZ, &ws);
}

static void				ft_write_output(t_env *e)
{
	char				buf[B_SIZE];
	int					len;

	ft_signal(SIGUSR1, ft_close_file);
	while (42)
	{
		ft_bzero(buf, B_SIZE);
		if ((read(e->fd_master, buf, B_SIZE)) == -1)
			ft_shutdown(e, 0);
		len = ft_strlen(buf);
		write(1, buf, len);
		write(e->fd_file, buf, len);
	}
}

static void				ft_write_input(t_env *e, int pid_child2)
{
	char				buf[B_SIZE];
	int					len;

	ft_signal(SIGWINCH, ft_resize);
	ft_resize(0);
	e->pid_zombie = pid_child2;
	while (42)
	{
		ft_bzero(buf, B_SIZE);
		if ((read(0, buf, B_SIZE)) == -1)
			ft_shutdown(e, pid_child2);
		len = ft_strlen(buf);
		write(e->fd_master, buf, len);
	}
}

void					ft_manage_input_output(t_env *e, int pid_child1)
{
	int					pid_child2;

	close(e->fd_slave);
	if ((pid_child2 = fork()) == -1)
	{
		kill(pid_child1, SIGKILL);
		_exit(-1);
	}
	else
	{
		if (!pid_child2)
			ft_write_output(e);
		else
			ft_write_input(e, pid_child2);
	}
}

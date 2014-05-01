/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 19:13:56 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 22:23:22 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "script.h"

void		ft_write_output(t_env *e)
{
	char	buf[4096];
	int		len;

	signal(SIGUSR1, ft_close); // CLOSE IF RECEIVES SIGNAL
	ft_bzero(buf, 4096);
	while (42)
	{
		if ((read(e->fd_master, buf, 4096)) == -1)
			ft_shutdown(e, 0);
		len = ft_strlen(buf);
		write(1, buf, len);
		write(e->fd_file, buf, len);
	}
}

void		ft_write_input(t_env *e, int pid)
{
	char	buf[4096];
	int		len;

	//DOES SIGWINCH - WHYYY???
	ft_bzero(buf, 4096);
	while (42)
	{
		if ((read(0, buf, 4096)) == -1)
			ft_shutdown(e, pid);
		len = ft_strlen(buf);
		write(e->fd_master, buf, len);
	}
}

void		ft_manage_input_output( t_env *e, int pid_child1)
{
	int		pid;

	printf("PARENT1\n");
	if ((pid = fork()) == -1 ) // PARENT PROCESS AGAIN
	{
		//UH OH SPAGHETTIOS
		printf("UH OH SPAGHETTIOS\n");
		kill(pid_child1, SIGKILL);
		_exit(-1);
	}
	else
	{
		if (!pid) // CHILD 2
		{
			printf("CHILD2\n");
			ft_write_output(e);
		}
		else // SECOND SON PROCESS
		{
			printf("PARENT2\n");
			ft_write_input(e, pid);
		}
	}

}

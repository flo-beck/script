/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 12:17:14 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 12:47:07 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/wait.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include "script.h"

/*
     int
	      gettimeofday(struct timeval *restrict tp, void *restrict tzp);


     struct timeval {
            time_t       tv_sec;    seconds since Jan. 1, 1970 
             suseconds_t  tv_usec; * and microseconds 
     };*/

void			ft_put_head(int fd)
{
	struct timeval	tp;
	struct timezone	tzp;

	if (-1 == (gettimeofday(&tp, &tzp)))
		printf("Failed to get time\n");
	write(fd, "Script started on ", 18);
	write(fd, ctime(&tp.tv_sec), 25);
}

void			ft_script(t_env *e)
{
	int			fd_master;
	int			fd_slave;
	static char	ptynamebuf[128];	/* ioctl knows length */
	int			pid;

	(void)pid;
	if (ft_get_pty(ptynamebuf, &fd_master))
		printf("Could not open free PTY pair!\n");

	if ((fd_slave = open(ptynamebuf, O_RDWR)) < 0) // OPEN SLAVE
	{
		printf("FAILED TO OPEN SLAVE\n");
		return ;
	}
	go_raw(0);
	/*if (fork()) // PARENT PROCESS
	{
		//wait(0);
		printf("PARENT\n");
		close(e->fd_file);
		close(fd_master);
		close(fd_slave);
		reset_terminal(0);
	}
	else // CHILD PROCESS
	{
		printf("CHILD\n");
		if (!e->op.q)
			ft_put_head(e->fd_file);*/
		/*dup(fd_slave, 0);
		dup(fd_slave, 1);
		dup(fd_slave, 2);*/
		close(e->fd_file);
		ft_exec_shell(e, fd_slave);
		/*close(e->fd_file);
		close(fd_master);
		close(fd_slave);*/
		reset_terminal(0);
	//}
}

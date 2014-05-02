/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pyt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 20:52:13 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/02 12:07:15 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "script.h"

int				ft_get_pty(char *ptynamebuf, int *fdm)
{
	struct stat	sbuf;

	if (((*fdm = open("/dev/ptmx", O_RDWR)) < 0)//get next available master
			|| (ioctl(*fdm, TIOCPTYGRANT) < 0)// open it up for RD and WR
			|| (ioctl(*fdm, TIOCPTYUNLK) < 0)// unlock the associated slave
			|| (ioctl(*fdm, TIOCPTYGNAME, ptynamebuf) < 0))// fill ptynamebuf
		return (-1);
	if ((stat(ptynamebuf, &sbuf) < 0)) //check its real?
		return (-1);
	//printf("the pseudo terminal is %s\n", ptynamebuf );
	return (0);
}


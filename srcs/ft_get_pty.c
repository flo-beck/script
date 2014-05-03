/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pyt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 20:52:13 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/03 21:31:37 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "script.h"

int				ft_get_pty(char *ptynamebuf, int *fdm)
{
	struct stat	sbuf;

	if (((*fdm = open("/dev/ptmx", O_RDWR)) < 0)
			|| (ioctl(*fdm, TIOCPTYGRANT) < 0)
			|| (ioctl(*fdm, TIOCPTYUNLK) < 0)
			|| (ioctl(*fdm, TIOCPTYGNAME, ptynamebuf) < 0))
		return (-1);
	if ((stat(ptynamebuf, &sbuf) < 0))
		return (-1);
	return (0);
}

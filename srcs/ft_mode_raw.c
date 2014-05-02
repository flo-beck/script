/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 11:59:05 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/02 17:09:55 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <termios.h>
#include "script.h"

int					go_raw(int fd)
{
	struct termios  newtermios;

	if ((ioctl(fd, TIOCGETA, &newtermios)) < 0)
		return (-1);
	newtermios.c_lflag &= ~(ICANON | ECHO | ISIG);
	newtermios.c_iflag &= ~(IXON | INLCR | IGNCR | ICRNL);
	newtermios.c_cc[VMIN] = 1;
	newtermios.c_cc[VTIME] = 0;
	if ((ioctl(fd, TIOCSETA, &newtermios)) < 0)
		return (-1);
	return (0);
}
/*
int					reset_terminal(int fd)
{
	struct termios  resetermios;

	if (tcgetattr(fd, &resetermios) < 0)
		return (-1);
	resetermios.c_lflag |= (ECHO | ICANON);
	if (tcsetattr(fd, TCSADRAIN, &resetermios) < 0)
		return (-1);
	return (0);
}*/

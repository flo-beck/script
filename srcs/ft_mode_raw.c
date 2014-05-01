/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 11:59:05 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/01 12:41:32 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include "script.h"

int					go_raw(int fd)
{
	struct termios  newtermios;

	if (tcgetattr(fd, &newtermios) < 0)
		return (-1);
	newtermios.c_lflag &= ~(ECHO | ICANON);
	newtermios.c_cc[VMIN] = 1;
	newtermios.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSADRAIN, &newtermios) < 0)
		return (-1);
	//setup_signal();
	return (0);
}

int					reset_terminal(int fd)
{
	struct termios  resetermios;

	if (tcgetattr(fd, &resetermios) < 0)
		return (-1);
	resetermios.c_lflag |= (ECHO | ICANON);
	if (tcsetattr(fd, TCSADRAIN, &resetermios) < 0)
		return (-1);
	//tputs(tgetstr("ei", NULL), 1, tputs_c);
	//reset_signal();
	return (0);
}

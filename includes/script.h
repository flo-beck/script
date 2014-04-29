/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:33:56 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/29 21:18:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCRIPT_H
# define SCRIPT_H

# include <stdio.h>//TAKE OUT!!!!

# define USE_MSG		"usage: script [-aq] [file [command ...]]"

typedef struct			s_ops
{
	int					op_a;
	int					op_q;
	int					err;
}						t_ops;

typedef struct			s_env
{
	int					index_filename;
	int					index_cmd;
	char				**av;
	t_ops				ops;
}						t_env;

/*
*	ft_parse_args.c
*/
int			ft_parse_args(t_env *e, int ac);

/*
*	ft_get_pty.c
*/
int			ft_get_pty(void);
/*
*	ft_error.c
*/
void		ft_op_err(char c);


#endif

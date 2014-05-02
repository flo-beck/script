/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:33:56 by fbeck             #+#    #+#             */
/*   Updated: 2014/05/02 17:58:51 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCRIPT_H
# define SCRIPT_H

# include <stdio.h>//TAKE OUT!!!!

# define USE_MSG		"usage: script [-aq] [file [command ...]]"
# define B_SIZE		(108)

typedef struct			s_ops
{
	int					a;
	int					q;
	int					err;
}						t_ops;

typedef struct			s_env
{
	char				**envp;
	char				*shell;
	char				*filename;
	int					fd_file;
	int					index_cmd;
	char				**av;
	t_ops				op;
	int					fd_master;
	int					fd_slave;
	int					pid_zombie;
}						t_env;

/*
**	ft_parse_args.c
*/
int			ft_parse_args(t_env *e, int ac);

/*
**	ft_open_file.c
*/
int			ft_open_file(t_env *e);

/*
**	ft_mode_raw.c
*/
int			go_raw(int fd);
int			reset_terminal(int fd);

/*
**	ft_get_pty.c
*/
int			ft_get_pty(char *ptynamebuf, int *fdm);

/*
**	ft_script.c
*/
void		ft_script(t_env *env);

/*
**	ft_exec_shell.c
*/
void		ft_exec_shell(t_env *e, int fd_slave);

/*
**	ft_input_output.c
*/
void		ft_manage_input_output(t_env *e, int pid_child1);
void		ft_write_input(t_env *e, int pid);
void		ft_write_ouput(t_env *e);
/*
**	ft_error.c
*/
void		ft_op_err(char c);

/*
**	ft_close.c
*/
void		ft_close_all(t_env *e);
void		ft_shutdown(t_env *e, int pid);
void		ft_close_file(int whatisthis);
void				ft_sigchild(int qqc);

t_env			*ft_get_env(void);

#endif

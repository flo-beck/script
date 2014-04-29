/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_save.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 19:41:30 by fbeck             #+#    #+#             */
/*   Updated: 2014/04/26 19:55:27 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_list	*ft_getnode(t_list **lst, int fd)
{
	t_list	*tmp;
	t_file	*new;

	tmp = *lst;
	while (tmp)
	{
		if (((t_file *)tmp->content)->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = (t_file *)malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->rem = NULL;
	new->fd = fd;
	new->read = 0;
	ft_lstadd_end(lst, ft_lstnew(new, sizeof(t_file)));
	free(new);
	return (ft_getnode(lst, fd));
}

static int		ft_treatrem(t_list *cur, char **line)
{
	int		index;
	char	*ptr;

	index = ft_indexof(CONTENT->rem, '\n');
	*line = ft_strsub(CONTENT->rem, 0, index);
	ptr = CONTENT->rem;
	CONTENT->rem = ft_strdup(CONTENT->rem + index + 1);
	free(ptr);
	return (1);
}

static int		ft_finalize(t_list *cur, char **line)
{
	if (CONTENT->rem && ft_strchr(CONTENT->rem, '\n'))
		return (ft_treatrem(cur, line));
	if (CONTENT->rem)
	{
		*line = ft_strdup(CONTENT->rem);
		free(CONTENT->rem);
		CONTENT->rem = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_list			*cur;
	char			buf[BUF_SIZE + 1];
	int				ret;

	if (BUF_SIZE < 1 || fd < 0)
		return (-1);
	cur = ft_getnode(&lst, fd);
	if (!cur)
		return (-1);
	if (CONTENT->rem && ft_strchr(CONTENT->rem, '\n'))
		return (ft_treatrem(cur, line));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		CONTENT->read = 1;
		CONTENT->rem = ft_strjoin(CONTENT->rem, buf);
		if (ft_strchr(CONTENT->rem, '\n'))
			return (ft_treatrem(cur, line));
	}
	return (ft_finalize(cur, line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_backup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 21:01:05 by fbeck             #+#    #+#             */
/*   Updated: 2014/01/26 21:01:08 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void		ft_fill_line(t_list **list, char **line, t_rem *rem,
		size_t size)
{
	char	*str;

	*line = (char *)malloc((size + 1) * sizeof(char));
	if (*line)
	{
		if (*(rem->rem) && (ft_strchr(rem->rem, '\n') == NULL))
		{
			ft_strcpy(*line, rem->rem);
			ft_bzero(rem->rem, (BUF_SIZE + 1));
		}
		else
		{
			ft_strcpy(*line, (char *)(*list)->content);
			(*list) = (*list)->next;
		}
		while ((*list))
		{
			ft_strcat(*line, (char *)(*list)->content);
			(*list) = (*list)->next;
		}
		str = ft_strchr(*line, '\n');
		rem->rem = (str) ? ft_strcpy(rem->rem, &str[1]) : rem->rem;
		if (str)
			str[0] = '\0';
	}
}

static size_t	ft_count_size_of_line(t_list *list)
{
	size_t		size;
	size_t		i;

	size = 0;
	i = 0;
	while (list)
	{
		if (ft_strchr((char *)list->content, '\n') == NULL)
			size = size + list->content_size;
		else
		{
			while (((char *)list->content)[i] != '\0'
					&& ((char *)list->content)[i] != '\n')
				i++;
			size = size + i;
			if (((char *)list->content)[i] == '\n')
				return (size);
		}
		list = list->next;
	}
	return (0);
}

static int		ft_look_in_rem(t_rem **rem, char **line)
{
	int		i;

	if (!*rem)
	{
		*rem = (t_rem *)malloc(sizeof(t_rem));
		(*rem)->rem = NULL;
		(*rem)->flag = 0;
		(*rem)->rem = (char *)malloc(BUF_SIZE + 1 * sizeof(char));
		ft_bzero((*rem)->rem, BUF_SIZE + 1);
	}
	if ((*rem)->flag == 0)
		return (0);
	if ((*rem)->rem && ft_strchr((*rem)->rem, '\n'))
	{
		i = ft_indexof((*rem)->rem, '\n');
		*line = ft_strsub((*rem)->rem, 0, i);
		(*rem)->rem = ft_memmove((*rem)->rem, &(((*rem)->rem)[i + 1]),
				(BUF_SIZE - i + 1));
		return (1);
	}
	return (0);
}

static int		ft_end_of_file(t_list *list, char **line, t_rem **rem, int ret)
{
	size_t			size;

	if (ret == -1)
		return (-1);
	if (!(*rem)->flag)
		return (0);
	if ((*rem)->rem && list)
	{
		size = ft_strlen(((*rem)->rem)) + ft_count_size_of_line(list);
		ft_fill_line(&list, line, (*rem), size);
		(*rem)->rem = NULL;
		return (1);
	}
	if ((*rem)->rem)
	{
		*line = ft_strdup((*rem)->rem);
		free((*rem)->rem);
		(*rem)->rem = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	t_list			*list;
	size_t			size;
	static t_rem	*rem = NULL;

	list = NULL;
	if (BUF_SIZE < 1 || fd < 0)
		return (-1);
	if (ft_look_in_rem(&rem, line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_lstpush(&list, buf, (ft_strlen(buf) + 1));
		rem->flag = 1;
		if (ft_strchr(buf, '\n'))
		{
			size = ft_strlen((rem->rem)) + ft_count_size_of_line(list);
			ft_fill_line(&list, line, rem, size);
			ft_lstdel(&list, ft_lstdel_elem);
			return (1);
		}
	}
	return (ft_end_of_file(list, line, &rem, ret));
}

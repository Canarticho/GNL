/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:30:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/07 07:18:49 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_readbuff(t_buff *buff)
{
	if (!(buff->buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	buff->size = read(buff->fd, buff->buff, BUFF_SIZE);
	if (buff->size <= 0)
	{
		free(buff->buff);
		return (buff->size);
	}
	return (1);
}

int		ft_extract_line(t_buff *buff, char **line, char *eol)
{
	char *tmp;
	char *res;

	if (buff->size == 0)
	{
		tmp = ft_strdup(buff->buff);
		if (buff->buff[0] == '\0')
		{
			free(buff->buff);
			return (0);
		}
		*line = tmp;
		free(buff->buff);
		return (1);
	}
	res = ft_strndup(buff->buff, (eol - buff->buff - 1));
	tmp = ft_strdup(++eol);
	free(buff->buff);
	buff->buff = tmp;
	*line = res;
	if (res && tmp)
		return (1);
	return (-1);
}

int		ft_get_line(t_buff *buff, char **line)
{
	char	*tmp;
	char	*eol;

	if (buff->buff && (((eol = ft_strchr(buff->buff, '\n'))) || !buff->size))
		return (ft_extract_line(buff, line, eol));
	tmp = ft_strnew(ft_strlen(buff->buff) + BUFF_SIZE + 1);
	if (buff->buff && buff->size)
	{
		ft_strcpy(tmp, buff->buff);
		free(buff->buff);
	}
	if (ft_readbuff(buff) > 0)
	{
		ft_strcat(tmp, buff->buff);
		free(buff->buff);
		buff->buff = tmp;
		return (ft_get_line(buff, line));
	}
	if (!buff->size)
	{
		buff->buff = tmp;
		return (ft_get_line(buff, line));
	}
	return (buff->size);
}

t_buff	*ft_addfd(t_buff *list, int fd)
{
	t_buff	*new;
	t_buff	*tmp;

	new = (t_buff *)malloc(sizeof(*list));
	new->buff = NULL;
	new->fd = fd;
	new->size = -1;
	new->next = NULL;
	if (!list)
	{
		list = new;
		return (list);
	}
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	*list;
	t_buff			*tmp;

	if (fd < 0)
		return (-1);
	if (!list)
		list = ft_addfd(list, fd);
	tmp = list;
	while (tmp && tmp->fd)
	{
		if (fd == tmp->fd)
		{
			if (tmp->size == 0)
				return (0);
			return (ft_get_line(tmp, line));
		}
		tmp = tmp->next;
	}
	return (ft_get_line(ft_addfd(list, fd), line));
}

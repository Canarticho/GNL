/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:30:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/28 12:13:31 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_readbuff(t_buff *buff)
{
	int size;

	if (!(buff->buff = ft_strnew(BUFF_SIZE)))
	{
		buff->siz = -1;
		return (-1);
	}
	size = read(buff->fd, buff->buff, BUFF_SIZE);
	if (size <= 0)
	{
		buff->siz = size;
		return (buff->siz);
	}
	return (1);
}

int		ft_extract_line(t_buff *buff, char **line, char *eol)
{
	char *tmp;
	char *res;

	if (buff->siz == 0)
	{
		if (buff->buff[0] == '\0')
		{
			free(buff->buff);
			return (0);
		}
		*line = ft_strdup(buff->buff);
		free(buff->buff);
		if (*line)
			return (1);
		return (-1);
	}
	res = ft_strndup(buff->buff, (eol - buff->buff));
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

	while (!(eol = ft_strchr(buff->buff, '\n')) && buff->siz > 0)
	{
		if (!(tmp = ft_strnew(buff->siz + BUFF_SIZE)))
			return (-1);
		ft_strcpy(tmp, buff->buff);
		free(buff->buff);
		if (ft_readbuff(buff) > 0)
			buff->siz = ft_strlcat(tmp, buff->buff, buff->siz + BUFF_SIZE + 1);
		free(buff->buff);
		buff->buff = tmp;
	}
	if (buff->siz >= 0 && buff->buff)
		return (ft_extract_line(buff, line, eol));
	return (buff->siz);
}

t_buff	*ft_addfd(t_buff *list, int fd)
{
	t_buff	*new;
	t_buff	*tmp;

	new = (t_buff *)malloc(sizeof(*list));
	new->buff = ft_strnew(1);
	new->fd = fd;
	new->siz = 1;
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

	if (fd < 0 || !line)
		return (-1);
	if (!list)
		list = ft_addfd(list, fd);
	tmp = list;
	while (tmp)
	{
		if (fd == tmp->fd)
		{
			if (tmp->siz == 0)
				return (0);
			return (ft_get_line(tmp, line));
		}
		tmp = tmp->next;
	}
	return (ft_get_line(ft_addfd(list, fd), line));
}

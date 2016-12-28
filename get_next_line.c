/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:30:40 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/28 04:07:49 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_readbuff(t_buff *buff)
{
	if (!(buff->buff = malloc(sizeof(char *) * (BUFF_SIZE + 1))))
		return (-1);
	ft_bzero(buff->buff, BUFF_SIZE + 1);
	buff->size = read(buff->fd, buff->buff, BUFF_SIZE);
	if (buff->size <= 0)
	{
		free(buff->buff);
		return (buff->size);
	}
	return (1);
}

char	*ft_extract_line(char **buff, char *eol)
{
	char *tmp;
	char *line;

	tmp = NULL;
	line = malloc(sizeof(line) * (eol - *buff + 1));
	ft_strncpy(line, *buff, eol - *buff);
	line[eol - *buff] = '\0';
	eol++;
	tmp = malloc(sizeof(*buff) * (ft_strlen(eol) + 1));
	ft_strcpy(tmp, eol);
	free(*buff);
	*buff = tmp;
	return (line);
}

int		ft_get_line(t_buff *buff, char **line)
{
	char *tmp;
	char *eol;

	if (buff->buff && buff->size > 0 && (eol = ft_strchr(buff->buff, '\n')))
	{
		*line = ft_extract_line(&buff->buff, eol);
		return (1);
	}
	tmp = malloc(sizeof(tmp) * (ft_strlen(buff->buff) + BUFF_SIZE + 1));
	ft_bzero(tmp, BUFF_SIZE + 1);
	if (buff->buff)
	{
		ft_strcpy(tmp, buff->buff);
		free(buff->buff);
	}
	if (ft_readbuff(buff) > 0)
	{
		ft_strlcat(tmp, buff->buff, ft_strlen(buff->buff) + BUFF_SIZE + 1);
		free(buff->buff);
		buff->buff = tmp;
		return (ft_get_line(buff, line));
	}
	if (buff->size > 0)
		buff->size = 1;
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

	if (!*line)
		free (*line);
	if (fd <= 2)
		return (-1);
	if (!list)
		list = ft_addfd(list, fd);
	tmp = list;
	while (tmp && tmp->fd)
	{
		if (fd == tmp->fd)
			return (ft_get_line(tmp, line));
		tmp = tmp->next;
	}
	return (ft_get_line(ft_addfd(list, fd), line));
	if (!tmp)
		return (-1);
}

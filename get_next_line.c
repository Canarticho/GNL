/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:30:40 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/21 05:59:52 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		ft_readbuff(t_buff *buff)
{
	ft_putstr("ft_readbuff\n");
	if (!(buff->buff = malloc(sizeof(char *) * (BUFF_SIZE + 1))))
		return (-1);
	ft_putstr("malloc ok\n");
	ft_bzero(buff->buff, BUFF_SIZE + 1);
	buff->size = read(buff->fd, buff->buff, BUFF_SIZE);
	ft_putnbr(buff->size);
	if (buff->size <= 0)
	{
		free(buff->buff);
		return (buff->size);
	}
	ft_putstr(buff->buff);
	return (1);
}

char	*ft_extract_line(char **buff, char *eol)
{
	char *tmp;

	tmp = NULL;
	free(buff);
	eol++;
	ft_putnbr(ft_strlen(eol));
	*buff = malloc(sizeof(*buff) * (ft_strlen(eol) + 1));
	ft_putstr(*buff);
	ft_strcpy(*buff, eol);
	return (tmp);
}

int		ft_get_line(t_buff *buff, char **line)
{
	char *tmp;
	char *eol;

	eol = NULL;
	tmp = NULL;
	ft_putstr("get line\n");
t a	ft_putnbr(buff->fd);
	if (buff->buff && buff->size > 0 && (eol = ft_strchr(buff->buff, '\n')))
	{
		tmp = ft_extract_line(&buff->buff, eol);
		ft_putstr("buff present\n");
		ft_putstr(tmp);
		ft_putchar('\n');
		ft_putstr(buff->buff);
		ft_putchar('\n');
		ft_putstr(eol);
		buff->buff = eol + 1;
		return (1);
	}
	ft_putstr("buff abs ou pas de \\n\n");
	if (buff->buff)
		tmp = malloc(sizeof(tmp) * (ft_strlen(buff->buff) + BUFF_SIZE + 1));
	else
		tmp = (char *)malloc(sizeof(tmp) * (BUFF_SIZE + 1));
	ft_bzero(tmp, BUFF_SIZE + 1);
	ft_putstr("bzero ok\n");
	if (buff->buff)
	{
		ft_strcpy(tmp, buff->buff);
		free(buff->buff);
	}
	if (ft_readbuff(buff) > 0)
	{
		ft_putstr("strlcat\n");
		ft_strlcat(tmp, buff->buff, ft_strlen(buff->buff) + BUFF_SIZE + 1);
		return (ft_get_line(buff, line));
	}
	return (buff->size);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff	*list;
	t_buff			*tmp;

	ft_putstr("GNL : \n");
	if (!list)
		list = ft_addfd(list, fd);
	if (!(tmp = ft_locate_buff(fd, list)))
		return (-1);
	ft_putstr("\nmaillon localise\n");
	return (ft_get_line(tmp, line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:43:08 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/21 03:38:27 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

t_buff	*ft_addfd(t_buff *list, int fd)
{
	t_buff	*tmp;

	tmp = (t_buff *)malloc(sizeof(list));
	tmp->buff = NULL;
	tmp->fd = fd;
	tmp->size = -1;
	if (!list)
	{
		ft_putstr("1er\n");
		return ((list = tmp));
	}
	while (list->next)
		list = list->next;
	ft_putstr("ajout\n");
	return ((list->next = tmp));
}

t_buff	*ft_locate_buff(int fd, t_buff *list)
{
	t_buff	*tmp;

	ft_putstr("locate_buff\n");
	if (!list)
	{
		ft_putstr("list a NULL \n");
		return (NULL);
	}
	tmp = list;
	ft_putstr("assign OK");
	ft_putnbr(tmp->fd);
	ft_putnbr(fd);
	while (fd != tmp->fd && tmp)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	ft_putstr("fd pas trouve : ");
	return (ft_addfd(list, fd));
}

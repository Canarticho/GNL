/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:43:08 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/28 00:52:38 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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

t_buff	*ft_locate_buff(int fd, t_buff *list)
{
	t_buff	*tmp;
	tmp = NULL;
	if (!list)
	{
		return (NULL);
	}
	tmp = list;
	while (tmp && tmp->fd)
	{
		if (fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (ft_addfd(list, fd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 02:49:29 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/25 01:02:09 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = -1;
	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size-- + 1)
		tmp[++i] = '\0';
	return (tmp);
}

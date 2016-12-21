/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 05:29:02 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/20 22:08:48 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (!dst && !src)
		return (0);
	i = -1;
	while (src[++i] && size)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:20:26 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/21 07:37:56 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i])
	{
		dest[i] = (char)src[i];
		i++;
	}
	while (i < len)
		(dest[i++]) = '\0';
	return (dest);
}

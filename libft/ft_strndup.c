/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:30:52 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/07 04:10:24 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *tmp;

	if (!(tmp = ft_strnew(n)))
		return (NULL);
	ft_strlcpy(tmp, s, n + 1);
	return (tmp);
}

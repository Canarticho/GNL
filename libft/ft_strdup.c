/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:13:46 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 11:15:40 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	tmp = ft_strcpy(tmp, s);
	return (tmp);
}

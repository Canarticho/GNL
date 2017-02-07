/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:55:04 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/25 03:52:14 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	str[11];
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	ft_bzero(str, 10);
	i = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (n / 10)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	str[i++] = n + '0';
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strdup(ft_strrev(str)));
}

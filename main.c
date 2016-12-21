/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:14:32 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/21 03:31:36 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		main(int ac, char **av)
{
	int		fd;
	char	**line;

	line = NULL;
	if (ac < 1)
		return (0);
	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY)))
		{
			ft_putnbr(fd);
			if (get_next_line(fd, line) > 0)
				ft_putstr(*line);
		}
	return (0);
}

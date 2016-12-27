/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:14:32 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/27 23:38:34 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int		main(int ac, char **av)
{
	int		fd;
	int fd2;
	char	**line;
	char	**line2;

	if (ac < 1)
		return (0);
	if (ac == 3)
	{
		line = malloc(sizeof(line));
		line2 = malloc(sizeof(line2));
		if ((fd = open(av[1], O_RDONLY)) && (fd2 = open(av[2],O_RDONLY)))
		{
			//			ft_putnbr(fd);
			while (get_next_line(fd, line) > 0 && get_next_line(fd2, line2) > 0)
			{
					ft_putstr("result : ");
					ft_putstr(*line);
					free(*line);
					ft_putchar('\n');
					ft_putstr("result : ");
					ft_putstr(*line2);
					free(*line2);
			}				
		}				
	}
	return (0);
}

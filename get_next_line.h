/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:42:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/10 07:04:35 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_buff
{
	char			*buff;
	int				fd;
	int				size;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);
t_buff				*ft_addfd(t_buff *list, int fd);
int					ft_get_line(t_buff *buff, char **line);
int					ft_readbuff(t_buff *buff);
t_buff				*ft_locate_buff(int fd, t_buff *list);
#endif

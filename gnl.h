/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 09:42:40 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/28 00:47:05 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define BUFF_SIZE 26
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

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
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strndup(const char *s, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
void				ft_putstr(const char *c);
void				ft_putnbr(int c);
void				ft_putchar(char c);
char				*ft_strncpy(char *dest, const char *src, size_t len);
#endif

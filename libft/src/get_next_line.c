/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:01:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:59:45 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int		verif_line(int fd, char **line, char **copy, t_read r)
{
	slow_down(2);
	if (r.i != 0 || (first_occ_of_char(*line, '\n') == -1
				&& first_occ_of_char(*line, '\0') > 0))
	{
		if (r.i != -2)
			ft_strdel(&copy[fd]);
		if (r.i == -1)
			return (-1);
		else
		{
			if (r.i > 0 && first_occ_of_char(*line, '\n') != -1)
				copy[fd] = strdup_free(r.buf[fd]);
			if ((r.i == -2 || r.i > 0) && first_occ_of_char(*line, '\n') >= 0)
			{
				line[0][first_occ_of_char(*line, '\n')] = '\0';
				r.i = ft_strlen(ft_strchr(copy[fd], '\n') + 1) + 1;
				copy[fd] = ft_memcpy(copy[fd],
						(ft_strchr(copy[fd], '\n') + 1), r.i);
			}
			return (1);
		}
	}
	if (r.buf[fd])
		ft_strdel(&r.buf[fd]);
	return (0);
}

int				get_next_line(const int fd, char **line, int start)
{
	static	char	*copy[2048];
	t_read			r;

	if (fd < 0 || fd > 2048 || BUFF_SIZE <= 0 || !line)
		return (-1);
	r.i = -2;
	r.buf[fd] = ft_strnew(BUFF_SIZE);
	if (!copy[fd])
		copy[fd] = strnew_del(BUFF_SIZE, copy[fd]);
	if (start == 0)
		ft_strdel(line);
	*line = ft_strdup(copy[fd]);
	while ((first_occ_of_char(*line, '\n') == -1)
			&& (r.i == BUFF_SIZE || r.i == -2))
	{
		r.i = read(fd, r.buf[fd], BUFF_SIZE);
		if (r.i >= 0)
		{
			r.buf[fd][r.i] = '\0';
			*line = strjoin_free1(*line, r.buf[fd]);
		}
	}
	return (verif_line(fd, line, copy, r));
}
*/
static int		verif_line(int fd, char **line, char **copy, t_read *r)
{
	slow_down(2);
	if (r->i != 0 || (first_occ_of_char(*line, '\n') == -1
				&& first_occ_of_char(*line, '\0') > 0))
	{
		if (r->i != -2)
			ft_strdel(&copy[fd]);
		if (r->i == -1)
			return (-1);
		else
		{
			if (r->i > 0 && first_occ_of_char(*line, '\n') != -1)
				copy[fd] = strdup_free(r->buf[fd]);
			if ((r->i == -2 || r->i > 0) && first_occ_of_char(*line, '\n') >= 0)
			{
				line[0][first_occ_of_char(*line, '\n')] = '\0';
				r->i = ft_strlen(ft_strchr(copy[fd], '\n') + 1) + 1;
				copy[fd] = ft_memcpy(copy[fd],
						(ft_strchr(copy[fd], '\n') + 1), r->i);
			}
			return (1);
		}
	}
	if (r->buf[fd])
		ft_strdel(&r->buf[fd]);
	return (0);
}

int				get_next_line(const int fd, char **line, int start)
{
	static	char	*copy[2048];
	t_read			*r;

	r = memalloc_sterr(sizeof(t_read), "Allocation problem in GNL");
	if (fd < 0 || fd > 2048 || BUFF_SIZE <= 0 || !line)
		return (-1);
	r->i = -2;
	r->buf[fd] = ft_strnew(BUFF_SIZE);
	if (!copy[fd])
		copy[fd] = strnew_del(BUFF_SIZE, copy[fd]);
	if (start == 0)
		ft_strdel(line);
	*line = ft_strdup(copy[fd]);
	while ((first_occ_of_char(*line, '\n') == -1)
			&& (r->i == BUFF_SIZE || r->i == -2))
	{
		r->i = read(fd, r->buf[fd], BUFF_SIZE);
		if (r->i >= 0)
		{
			r->buf[fd][r->i] = '\0';
			*line = strjoin_free1(*line, r->buf[fd]);
		}
	}
	return (verif_line(fd, line, copy, r));
}

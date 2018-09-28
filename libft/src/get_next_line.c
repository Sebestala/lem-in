/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:01:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/28 19:46:40 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static void		put_in_str(int fd, char **line, char **copy, char **buf)
{
	int		i;
	int		j;

	j = 0;
	i = first_occ_of_char(copy[fd], '\n');
	if (i == -1)
	{
		*line = ft_strdup(copy[fd]);
		ft_strdel(&copy[fd]);
		ft_strdel(&buf[fd]);
		return ;
	}
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, copy[fd], i);
	while (copy[fd] && copy[fd][i + j])
		j++;
	buf[fd] = strnew_del(j, buf[fd]);
	j = 0;
	while ((first_occ_of_char(copy[fd], '\0') >= i + j + 1) && copy[fd] && copy[fd][i + j + 1])
	{
		buf[fd][j] = copy[fd][i + j + 1];
		j++;
	}
	ft_strdel(&copy[fd]);
	copy[fd] = ft_strdup(buf[fd]);
	ft_strdel(&buf[fd]);
}

static int		gnl2(int fd, char **line, char **copy, char **buf)
{
	int		i;

	if (copy[fd])
		ft_strdel(line);
	else
		copy[fd] = ft_strnew(BUFF_SIZE);
	i = first_occ_of_char(copy[fd], '\n');
	buf[fd] = ft_strnew(BUFF_SIZE);
	if (i >= 0)
		put_in_str(fd, line, copy, buf);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char		*copy[2048];
	char			*buf[2048];
	int				i;

	if (fd < 0 || fd > 1048 || BUFF_SIZE <= 0 || !line)
		return (-1);
	i = gnl2(fd, line, copy, buf);
	if (i == -1)
	{
		i = BUFF_SIZE;
		while (first_occ_of_char(copy[fd], '\n') == -1 && i == BUFF_SIZE)
		{
			i = read(fd, buf[fd], BUFF_SIZE);
			if (i < 0)
				return (-1);
			if (i != 0)
				copy[fd] = strjoin_free1(copy[fd], buf[fd]);
		}
		put_in_str(fd, line, copy, buf);
		if (i == 0)
			ft_strdel(&copy[fd]);
	}
	if (i == 0 && !copy[fd])
		return ((ft_strlen(*line) > 0) ? 1 : 0);
	return (1);
}

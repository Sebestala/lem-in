/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:18:32 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/19 21:43:16 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
static void			put_str_id_path(t_ant *ant)
{
	t_room	*room;
	t_path	*path;
	int		i;

	room = ant->room;
	path = ant->path;
	while (room)
	{
		i = 0;
		room->id_path = ft_strnew(ant->nb_path + 2);
		while (i <= ant->nb_path + 1)
			room->id_path[i++] = '0';
		room = room->next;
	}
	while (path)
	{
		i = 0;
		path->id_path = ft_strnew(ant->nb_path + 2);
		while (i <= ant->nb_path + 1)
			path->id_path[i++] = '0';
		path = path->next;
	}
}

static t_ant		*id_path(t_ant *ant, t_path *path, t_room *room)
{
	int	i;

	i = 0;
	if (room != ant->start && room != ant->end)
		path->power++;
	while (path->id_path[i])
	{
		if (room->id_path[i] == '1')
			path->id_path[i] = '1';
		i++;
	}
	return (ant);
}

t_ant				*put_id_path(t_ant *ant)
{
	t_path	*ptr;
	t_ptr	*ptr2;

	put_str_id_path(ant);
	ptr = ant->path;
	while (ptr != NULL)
	{
		ptr2 = ptr->room;
		while (ptr2 != NULL)
		{
			if (ptr2->ptr_room != ant->start && ptr2->ptr_room != ant->end)
				ptr2->ptr_room->id_path[ptr->id] = '1';
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	ptr = ant->path;
	while (ptr != NULL)
	{
		ptr2 = ptr->room;
		while (ptr2 != NULL)
		{
			ant = id_path(ant, ptr, ptr2->ptr_room);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (ant);
}

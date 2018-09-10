/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:18:32 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/29 19:09:32 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant		*id_path2(t_ant *ant, t_path *path, int id)
{
	t_ptr	*ptr;

	ptr = memalloc_sterr(sizeof(t_ptr), "id_path2");
	while (path->id_path->next != NULL)
		path->id_path = path->id_path->next;
	if (path->id_path != NULL)
	{
		ptr->back = path->id_path;
		path->id_path->next = ptr;
	}
	else
		path->id_path = ptr;
	ptr->id = id;
	return (ant);
}

static t_ant		*id_path(t_ant *ant, t_path *path, t_room *room)
{
	t_ptr	*ptr;

	if (room != ant->start && room != ant->end)
		path->power++;
	while (room->id_path != NULL)
	{
		ptr = path->id_path;
		while (ptr != NULL)
		{
			if (room->id_path->id == ptr->id)
				break ;
			else
				ptr = ptr->next;
		}
		if (ptr == NULL)
			id_path2(ant, path, room->id_path->id);
		room->id_path = room->id_path->next;
	}
	return (ant);
}

static t_ant		*put_id_room(t_ant *ant, t_room *room, int id)
{
	t_ptr	*ptr;

	ptr = memalloc_sterr(sizeof(t_ptr), "put_id_room");
	ptr->id = id;
	if (room->id_path != NULL)
	{
		while (room->id_path->next != NULL)
			room->id_path = room->id_path->next;
		ptr->back = room->id_path;
		room->id_path->next = ptr;
	}
	else
		room->id_path = ptr;
	return (ant);
}

t_ant				*put_id_path(t_ant *ant)
{
	t_ptr	*ptr;

	ptr = ant->path;
	while (ptr != NULL)
	{
		while (ptr->ptr_path->room != NULL)
		{
			if (ptr->ptr_path->room->ptr_room != ant->start
					&& ptr->ptr_path->room->ptr_room != ant->end)
				ant = put_id_room(ant, ptr->ptr_path->room->ptr_room, ptr->id);
			ptr->ptr_path->room = ptr->ptr_path->room->next;
		}
		ptr = ptr->next;
	}
	ptr = ant->path;
	while (ptr != NULL)
	{
		while (ptr->ptr_path->room != NULL)
		{
			ant = id_path(ant, ptr->ptr_path, ptr->ptr_path->room->ptr_room);
			ptr->ptr_path->room = ptr->ptr_path->room->next;
		}
		ptr = ptr->next;
	}
	return (ant);
}

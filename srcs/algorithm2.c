/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:18:32 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/10 19:06:09 by sgarcia          ###   ########.fr       */
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
	t_ptr	*ptr2;

	ptr2 = room->id_path;
	if (room != ant->start && room != ant->end)
		path->power++;
	while (ptr2 != NULL)
	{
		ptr = path->id_path;
		while (ptr != NULL)
		{
			if (ptr2->id == ptr->id)
				break ;
			else
				ptr = ptr->next;
		}
		if (ptr == NULL)
			id_path2(ant, path, ptr2->id);
		ptr2 = ptr2->next;
	}
	return (ant);
}

static t_ant		*put_id_room(t_ant *ant, t_room *room, int id)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;

	ptr = memalloc_sterr(sizeof(t_ptr), "put_id_room");
	ptr->id = id;
	ptr2 = room->id_path;
	if (ptr2 != NULL)
	{
		while (ptr2->next != NULL)
			ptr2 = ptr2->next;
		ptr->back = ptr2;
		ptr2->next = ptr;
	}
	else
		ptr2 = ptr;
	return (ant);
}

t_ant				*put_id_path(t_ant *ant)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;

	ptr = ant->path;
	while (ptr != NULL)
	{
		ptr2 = ptr->ptr_path->room;
		while (ptr2 != NULL)
		{
			if (ptr2->ptr_room != ant->start && ptr2->ptr_room != ant->end)
				ant = put_id_room(ant, ptr2->ptr_room, ptr->id);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	ptr = ant->path;
	while (ptr != NULL)
	{
		ptr2 = ptr->ptr_path->room;
		while (ptr2 != NULL)
		{
			ant = id_path(ant, ptr->ptr_path, ptr2->ptr_room);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (ant);
}

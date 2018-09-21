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
//	printf("put_str_id_path   nb_path = %d\n", ant->nb_path);
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
//	printf("id_path\n");
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
	t_path	*path;
	t_ptr	*ptr2;

	put_str_id_path(ant);
	path = ant->path;
	while (path != NULL)
	{
		ptr2 = path->room;
		while (ptr2 != NULL)
		{
//	printf("TEST2   id path = %d    ptr_room = %p\n", path->id, ptr2->ptr_room);
//	fflush(stdout);
			if (ptr2->ptr_room != ant->start && ptr2->ptr_room != ant->end)
				ptr2->ptr_room->id_path[path->id] = '1';
//	printf("TEST1\n");
//	fflush(stdout);
			ptr2 = ptr2->next;
		}
		path = path->next;
	}
//	printf("TEST\n");
	path = ant->path;
	while (path != NULL)
	{
		ptr2 = path->room;
		while (ptr2 != NULL)
		{
			ant = id_path(ant, path, ptr2->ptr_room);
			ptr2 = ptr2->next;
		}
		path = path->next;
	}
	return (ant);
}

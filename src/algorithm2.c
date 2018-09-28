/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:18:32 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/28 18:57:34 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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

static void			put_id_path3(t_ant *ant, t_tab *tab, t_path *path)
{
	int		i;
	t_room	*room;

	while (tab)
	{
		i = 0;
		while (tab->tab[i])
		{
			room = tab->tab[i];
			if (room != ant->start && room != ant->end)
				room->id_path[path->id] = '1';
			i++;
		}
		tab = tab->next;
	}
}

static void			put_id_path2(t_ant *ant, int j, int k)
{
	t_path	*path;
	t_tab2	*tab2;

	while (ant->path[j])
	{
		tab2 = ant->path[j];
		k = 0;
		while (tab2->tab2[k])
		{
			path = tab2->tab2[k];
			put_id_path3(ant, path->room, path);
			k++;
		}
		j++;
	}
}

static void			put_id_path1(t_ant *ant, t_tab *tab, t_path *path)
{
	int		i;
	t_room	*room;

	while (tab)
	{
		i = 0;
		while (tab->tab[i])
		{
			room = tab->tab[i];
			ant = id_path(ant, path, room);
			i++;
		}
		tab = tab->next;
	}
}

t_ant				*put_id_path(t_ant *ant, int j, int k)
{
	t_path	*path;
	t_tab2	*tab2;

	put_str_id_path(ant, ant->room, 0, 0);
	put_id_path2(ant, j, k);
	while (ant->path[j])
	{
		tab2 = ant->path[j];
		k = 0;
		while (tab2->tab2[k])
		{
			path = tab2->tab2[k];
			put_id_path1(ant, path->room, path);
			k++;
		}
		j++;
	}
	return (ant);
}

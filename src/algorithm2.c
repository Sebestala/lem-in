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
	t_tab2	*tab;
	int		i;
	int		j;
	int		k;

	room = ant->room;
	while (room)
	{
		i = 0;
		room->id_path = ft_strnew(ant->nb_path + 2);
		while (i <= ant->nb_path + 1)
			room->id_path[i++] = '0';
		room = room->next;
	}
	i = 0;
	while (ant->path[i])
	{
		tab = ant->path[i];
		j = 0;
		while (tab->tab2[j])
		{
			k = 0;
			path = tab->tab2[j];
			path->id_path = ft_strnew(ant->nb_path + 2);
			while (k <= ant->nb_path + 1)
				path->id_path[k++] = '0';
			j++;
		}
		i++;
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
	t_room	*room;
	t_tab2	*tab2;
	t_tab	*tab;
	int		i;
	int		j;
	int		k;

	put_str_id_path(ant);
	j = 0;
	while (ant->path[j])
	{
		tab2 = ant->path[j];
		k = 0;
		while (tab2->tab2[k])
		{
			path = tab2->tab2[k];
			tab = path->room;
			while (tab)
			{
				i = 0;
				while (tab->tab[i])
				{
					room = tab->tab[i];
					if (room != ant->start && room != ant->end)
						room->id_path[path->id] = '1';
					i++;
					if (i % 100 == 0)
						tab = tab->next;
				}
				tab = tab->next;
			}
			k++;
		}
		j++;
	}
	j = 0;
	while (ant->path[j])
	{
		tab2 = ant->path[j];
		k = 0;
		while (tab2->tab2[k])
		{
			path = tab2->tab2[k];
			tab = path->room;
			while (tab)
			{
				i = 0;
				while (tab->tab[i])
				{
				room = tab->tab[i];
				ant = id_path(ant, path, room);
				i++;
				if (i % 100 == 0)
					tab = tab->next;
				}
				tab = tab->next;
			}
			k++;
		}
		j++;
	}
	return (ant);
}

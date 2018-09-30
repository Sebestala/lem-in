/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm0_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:23:24 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/30 14:42:16 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_ant		*make_enter_path(t_ant *ant)
{
	t_path	*path;
	t_tab	*struct_ptr_in_path;

	path = memalloc_sterr(sizeof(t_path), "make_enter_path");
	struct_ptr_in_path = memalloc_sterr(sizeof(t_tab), "make_enter_path");
	if (!ant->path[0])
	{
		make_tab2(ant, path);
		ant->path_end = path;
	}
	else
	{
		path->id = ant->path_end->id;
		ant->path_end = path;
		put_path_in_tab2(ant, path);
	}
	path->id = ant->path_end->id + 1;
	path->room = struct_ptr_in_path;
	struct_ptr_in_path->tab[0] = ant->start;
	return (ant);
}

t_ant		*valid_path(t_ant *ant)
{
	t_tab	*tab;
	t_room	*room;
	int		i;

	tab = ant->path_end->room;
	ant = make_enter_path(ant);
	while (tab)
	{
		i = 0;
		while (tab->tab[i])
		{
			room = tab->tab[i];
			ant = make_ptr_path(ant, room);
			i++;
		}
		tab = tab->next;
	}
	if (ant->path_end->id % 10000 == 0)
		ft_printf(" NB PATH = %d\n", ant->path_end->id);
	return (ant);
}

t_ant		*on_end(t_ant *ant)
{
	ant = valid_path(ant);
	ant->start->check++;
	ant = del_ptr_path(ant);
	return (ant);
}

t_ant		*find_end(t_ant *ant, t_room *ptr, t_room *element)
{
	while (ptr != NULL)
	{
		if (ptr == ant->end)
			break ;
		ptr = room_in_tab_tube(element);
		element->check++;
	}
	if (ptr != NULL)
	{
		ant = make_ptr_path(ant, ptr);
		ant = valid_path(ant);
		ant = del_ptr_path(ant);
	}
	else
		exit_str("Error : end's room not find");
	return (ant);
}

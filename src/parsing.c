/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:10:47 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/28 19:34:56 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_ant				*init_struct_room(t_ant *ant)
{
	t_room		*room;

	room = memalloc_sterr(sizeof(t_room), "init_struct");
	if (ant->line[ant->i] && ant->line[ant->i] == 'L')
		exit_str("Error : enter is incorrect");
	while (ant->line[ant->i] && ant->line[ant->i] != ' ')
		ant->i++;
	room->name = memalloc_sterr(ant->i, "init_struct");
	room->name = ft_strncpy(room->name, ant->line, ant->i);
	if (verif_name(ant, room->name) > 0)
		exit_str("Error : 2 room have the same name");
	if (!ant->room)
	{
		ant->room = room;
		ant->room_end = room;
	}
	else
	{
		room->id = ant->room_end->id + 1;
		ant->room_end->next = room;
		ant->room_end = room;
	}
	return (ant);
}

static void			path2(t_room *room, t_room *room0, t_room *room1, int i)
{
	t_tab	*tab;
	t_tab	*tab2;

	while (i < 2)
	{
		tab = room->tube;
		if (tab)
			room->tube_end++;
		if (tab != NULL && room->tube_end % 100 == 0)
		{
			while (tab->next)
				tab = tab->next;
			tab2 = memalloc_sterr(sizeof(t_tab), "path2");
			tab->next = tab2;
		}
		if (room->tube == NULL)
			room->tube = memalloc_sterr(sizeof(t_tab), "path2");
		tab = room->tube;
		while (tab->next)
			tab = tab->next;
		tab->tab[room->tube_end % 100] = room0;
		room1 = room0;
		room0 = room;
		room = room1;
		i++;
	}
}

static t_room		*path1(t_ant *ant, int nb, int i)
{
	t_room		*begin;

	begin = ant->room;
	while (begin != NULL)
	{
		if (!ft_strncmp(ant->line + i, begin->name, nb)
		&& ft_strlen(begin->name) == (size_t)nb)
			break ;
		begin = begin->next;
	}
	if (begin == NULL)
		exit_str("Error : room enter in path1 is incorrect");
	return (begin);
}

static t_ant		*path(t_ant *ant)
{
	t_room		*room1;
	t_room		*room2;

	while (ant->line[ant->i] && ant->line[ant->i] != '-')
		ant->i++;
	room1 = path1(ant, ant->i, 0);
	ant->i++;
	while (ant->line[ant->i + ant->j])
		ant->j++;
	room2 = path1(ant, ant->j, ant->i);
	path2(room1, room2, NULL, 0);
	return (ant);
}

t_ant				*init_room(t_ant *ant)
{
	while (get_next_line(0, &ant->line))
	{
		ft_putendl(ant->line);
		ant = init_ant(ant);
		ant = comment(ant);
		ant = command(ant);
		if (ant->check == 0 && !is_str_on(ant->line, " ") && ant->line[0] && ant->line[0] != '#')
			ant->check = 1;
		if (ant->check == 0)
		{
			if (ant->line[0] && ant->line[0] != '#')
			{
				ant = init_struct_room(ant);
				ant = init_room2(ant);
			}
		}
		if (ant->check == 1)
			ant = path(ant);
	}
	write(1, "\n", 1);
	return (ant);
}

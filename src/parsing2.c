/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 23:47:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/19 17:20:20 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"
/*
void	make_room_tab(t_ant *ant)
{
	int		i;
	t_room	*room;

	ant->room_tab = memalloc_sterr(sizeof(t_room *) * (ant->room_end->id + 1), "make_room_tab");
	i = 0;
	room = ant->room;
	while (room)
	{
		ant->room_tab[i] = room;
		room = room->next;
		i++;
	}
}
*/
int		finish(t_ant *ant)
{
	t_pawn	*pawn;

	pawn = ant->pawn;
	while (pawn)
	{
		if (pawn->check != -1)
			return (0);
		pawn = pawn->next;
	}
	return (1);
}

t_ant	*find_final_room(t_ant *ant)
{
	t_tab	*begin;
	t_room	*room;
	int		i;

	i = 0;
	begin = ant->start->tube;
	while(i <= ant->start->tube_end)
	{
		room = begin->tab[i % 100];
		if (room != ant->end && room->last_room == 0)
			room->last_room = -1;
		i++;
		if (i % 100 == 0)
			begin = begin->next;
	}
	i = 0;
	begin = ant->end->tube;
	while(i <= ant->end->tube_end)
	{
		room = begin->tab[i % 100];
		if (room != ant->start)
			room->last_room = 1;
		i++;
		if (i % 100 == 0)
			begin = begin->next;
	}
	return (ant);
}

int		verif_name(t_ant *ant, char *name2)
{
	t_room	*room;

	room = ant->room;
	while (room != NULL)
	{
		if (!ft_strcmp(room->name, name2))
		{
			room = ant->room;
			return (1);
		}
		room = room->next;
	}
	return (0);
}

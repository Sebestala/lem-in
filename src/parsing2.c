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
	t_ptr	*begin;
	t_room	*room;

	begin = ant->end->tube;
	while(begin != NULL)
	{
		room = begin->ptr_room;
		if (room != ant->start)
			room->last_room = 1;
		begin = begin->next;
	}
	begin = ant->start->tube;
	while(begin != NULL)
	{
		room = begin->ptr_room;
		if (room != ant->end && room->last_room == 0)
			room->last_room = -1;
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

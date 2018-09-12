/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 23:47:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:47:05 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

	begin = ant->end->tube;
	while(begin != NULL)
	{
		if (begin->ptr_room != ant->start)
			begin->ptr_room->last_room = 1;
		begin = begin->next;
	}
	return (ant);
}

int		verif_name(t_ant *ant, char *name2)
{
	t_ptr	*room;

	room = ant->room;
	while (room != NULL)
	{
		if (!ft_strcmp(room->ptr_room->name, name2))
		{
			room = ant->room;
			return (1);
		}
		room = room->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 23:47:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/23 20:58:57 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant	find_final_room(t_ant ant)
{
	while(ant.end->tube != NULL)
	{
		if (ant.end->tube->ptr_room != ant.start)
			ant.end->tube->ptr_room->last_room = 1;
		ant.end->tube = ant.end->tube->next;
	}
	return (ant);
}

int		verif_name(t_ant ant, char *name2)
{
	while (ant.room != NULL)
	{
		if (ft_strcmp(ant.room->ptr_room->name, name2))
		{
			ant.room = ant.room_begin;
			return (1);
		}
		ant.room = ant.room->next;
	}
	ant.room = ant.room_begin;
	return (0);
}

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

t_ant		*init_room2(t_ant *ant)
{
	ant->i++;
	if (ant->line[ant->i] && ant->line[ant->i] >= '0' && ant->line[ant->i] <= '9')
		ant->j++;
	while (ant->line[ant->i] && ant->line[ant->i] >= '0' && ant->line[ant->i] <= '9')
		ant->i++;
	if (ant->line[ant->i] && ant->line[ant->i] == ' ')
		ant->j++;
	if (ant->line[ant->i] && ant->line[ant->i] == ' ')
		ant->i++;
	if (ant->line[ant->i] && ant->line[ant->i] >= '0' && ant->line[ant->i] <= '9')
		ant->j++;
	while (ant->line[ant->i] && ant->line[ant->i] >= '0' && ant->line[ant->i] <= '9')
		ant->i++;
	if (ant->line[ant->i] != '\0' || ant->j != 3)
	{
		ft_putendl(ant->line);
		exit_str("Error : room enter is incorrect");
	}
	ant = init_ant(ant);
	return (ant);
}

int			finish(t_ant *ant)
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

t_ant		*find_final_room(t_ant *ant)
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

int			verif_name(t_ant *ant, char *name2)
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

t_ant		*command(t_ant *ant)
{
	int		i;

	i = 0;
	if (ft_strcmp(ant->line, "##start") == 0)
		i = 1;
	if (ft_strcmp(ant->line, "##end") == 0)
		i = 2;
	if ((i == 1 && ant->start != NULL) || (i == 2 && ant->end != NULL))
		exit_str("Error : there must be only 1 start and 1 end");
	if (i > 0)
	{
		get_next_line(0, &ant->line);
		ft_putendl(ant->line);
		ant = comment(ant);
		ant = init_struct_room(ant);
		if (i == 1)
			ant->start = ant->room_end;
		if (i == 2)
			ant->end = ant->room_end;
		ant = init_room2(ant);
		get_next_line(0, &ant->line);
		ft_putendl(ant->line);
		ant = command(ant);
	}
	return (ant);
}

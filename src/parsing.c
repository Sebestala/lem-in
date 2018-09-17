/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:10:47 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/23 20:29:07 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static t_ant	*init_struct(t_ant *ant)
{
	t_room		*room;
	t_ptr		*room2;
	t_ptr		*ptr;

	room = memalloc_sterr(sizeof(t_room), "init_struct");
	ptr = memalloc_sterr(sizeof(t_ptr), "init_struct");
	if (ant->line[ant->i] && ant->line[ant->i] == 'L')
		exit_str("Error : enter is incorrect");
	while (ant->line[ant->i] && ant->line[ant->i] != ' ')
		ant->i++;
	room->name = memalloc_sterr(ant->i, "init_struct");
	room->name = ft_strncpy(room->name, ant->line, ant->i);
	if (verif_name(ant, room->name) > 0)
		exit_str("Error : dynamic allocation problem in init_struct");
	ptr->ptr_room = room;
	if (!ant->room)
		ant->room = ptr;
	else
	{
		room2 = ant->room;
		while (room2->next != NULL)
			room2 = room2->next;
		room2->next = ptr;
		ptr->back = room2;
	}
	return (ant);
}

static t_ant		*init_room2(t_ant *ant)
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

t_ant		*command(t_ant *ant, t_ptr *ptr)
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
		ant = init_struct(ant);
		ptr = ant->room;
		while (ptr->next != NULL)
			ptr = ptr->next;
		if (i == 1)
			ant->start = ptr->ptr_room;
		if (i == 2)
			ant->end = ptr->ptr_room;
		ant = init_room2(ant);
		get_next_line(0, &ant->line);
		ft_putendl(ant->line);
		ant = command(ant, ant->room);
	}
	return (ant);
}

static void			path2(t_room *room1, t_room *room2)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;
	t_ptr	*begin;

	ptr = memalloc_sterr(sizeof(t_ptr), "path2");
	ptr2 = memalloc_sterr(sizeof(t_ptr), "path2");
	ptr->ptr_room = room1;
	ptr2->ptr_room = room2;
	if (room1->tube == NULL)
		room1->tube = ptr2;
	else
	{
		begin = room1->tube;
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = ptr2;
		ptr2->back = begin;
	}
	if (room2->tube == NULL)
		room2->tube = ptr;
	else
	{
		begin = room2->tube;
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = ptr;
		ptr->back = begin;
	}
}

static t_room		*path1(t_ant *ant, int nb, int i)
{
	t_ptr	*begin;

	begin = ant->room;
	while (begin != NULL)
	{
		if (!ft_strncmp(ant->line + i, begin->ptr_room->name, nb)
			&& ft_strlen(begin->ptr_room->name) == (size_t)nb)
			break ;
		begin = begin->next;
	}
	if (begin == NULL)
		exit_str("Error : room enter in path1 is incorrect");
	return (begin->ptr_room);
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
	path2(room1, room2);
	return (ant);
}

t_ant				*init_room(t_ant *ant)
{
	while (get_next_line(0, &ant->line))
	{
		ft_putendl(ant->line);
		ant = init_ant(ant);
		ant = comment(ant);
		ant = command(ant, ant->room);
		if (ant->check == 0 && !is_str_on(ant->line, " ") && ant->line[0] && ant->line[0] != '#')
			ant->check = 1;
		if (ant->check == 0)
		{
			if (ant->line[0] && ant->line[0] != '#')
			{
				ant = init_struct(ant);
				ant = init_room2(ant);
			}
		}
		if (ant->check == 1)
			ant = path(ant);
	}
	write(1, "\n", 1);
	return (ant);
}

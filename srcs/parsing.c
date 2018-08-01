/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:10:47 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/01 19:47:56 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant	init_struct(t_ant ant)
{
	t_room		room;
	t_ptr		ptr;

	if (ant.line[ant.i] && ant.line[ant.i] == 'L')
		exit_str("Error : enter is incorrect");
	while (ant.line[ant.i] && ant.line[ant.i] != ' ')
		ant.i++;
	if (!(room.name = (char *)malloc(ant.i * sizeof(char))))
		exit_str("Error : dynamic allocation problem in init_struct");
	ft_bzero(&room, sizeof(t_room));
	ft_bzero(&ptr, sizeof(t_ptr));
	room.name = ft_strncpy(room.name, ant.line, ant.i);
	if (verif_name(ant, room.name) > 0)
		exit_str("Error : dynamic allocation problem in init_struct");
	ptr.ptr_room = &room;
	if (!ant.room)
	{
		ant.room = &ptr;
		ant.room_begin = &ptr;
	}
	else
	{
		while (ant.room->next != NULL)
			ant.room = ant.room->next;
		ant.room->next = &ptr;
		ant.room = ant.room_begin;
	}
	return (ant);
}

static t_ant		init_room2(t_ant ant)
{
	ant.i++;
	if (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.j++;
	while (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.i++;
	if (ant.line[ant.i] && ant.line[ant.i] == ' ')
		ant.j++;
	if (ant.line[ant.i] && ant.line[ant.i] == ' ')
		ant.i++;
	if (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.j++;
	while (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.i++;
	if (ant.line[ant.i] != '\0' || ant.j != 3)
		exit_str("Error : room enter is incorrect");
	return (ant);
}

t_ant		command(t_ant ant)
{
	int		i;

	i = 0;
	if (ft_strcmp(ant.line, "##start"))
		i = 1;
	if (ft_strcmp(ant.line, "##end"))
		i = 2;
	if ((i == 1 && ant.start != NULL) || (i == 2 && ant.end != NULL))
		exit_str("Error : there must be only 1 start and 1 end");
	if (i > 0)
	{
		get_next_line(0, &ant.line, 0);
		ant.i = 0;
		ant.j = 0;
		ant = comment(ant);
		ant = init_struct(ant);
		while (ant.room->next != NULL)
			ant.room = ant.room->next;
		if (i == 1)
			ant.start = ant.room->ptr_room;
		if (i == 2)
			ant.end = ant.room->ptr_room;
		ant.room = ant.room_begin;
		ant = init_room2(ant);
		get_next_line(0, &ant.line, 0);
	}
	return (ant);
}

static void			path2(t_room *room1, t_room *room2)
{
	t_ptr	ptr;
	t_ptr	ptr2;

	ft_bzero(&ptr, sizeof(t_ptr));
	ft_bzero(&ptr2, sizeof(t_ptr));
	ptr.ptr_room = room1;
	ptr2.ptr_room = room2;
	if (room1->tube == NULL)
		room1->tube = &ptr2;
	else
	{
		while (room1->tube->next != NULL)
			room1->tube = room1->tube->next;
		room1->tube->next = &ptr2;
	}
	if (room2->tube == NULL)
		room2->tube = &ptr;
	else
	{
		while (room2->tube->next != NULL)
			room2->tube = room2->tube->next;
		room2->tube->next = &ptr;
	}
}

static t_ant		path(t_ant ant)
{
	t_room		*room1;
	t_room		*room2;

	while (ant.line[ant.i] && ant.line[ant.i] != '-')
		ant.i++;
	while (!ft_strncmp(ant.line, ant.room->ptr_room->name, ant.i)
			&& ant.room->ptr_room->name[ant.i] == '\0')
	{
		if (ant.room == NULL)
			exit_str("Error : room enter in 2nd part is incorrect");
		ant.room = ant.room->next;
	}
	room1 = ant.room->ptr_room;
	ant.room = ant.room_begin;
	ant.i++;
	while (ant.line[ant.i + ant.j])
		ant.j++;
	while (!ft_strncmp(ant.line, ant.room->ptr_room->name, ant.j)
			&& ant.room->ptr_room->name[ant.j] == '\0')
	{
		if (ant.room == NULL)
			exit_str("Error : room enter in 2nd part is incorrect");
		ant.room = ant.room->next;
	}
	room2 = ant.room->ptr_room;
	path2(room1, room2);
	return (ant);
}

t_ant				init_room(t_ant ant)
{
	while (get_next_line(0, &ant.line, 0))
	{
		ant.i = 0;
		ant.j = 0;
		ant = comment(ant);
		if (ant.check == 0 && !is_str_on(ant.line, " "))
			ant.check = 1;
		if (ant.check == 0)
		{
			ant = command(ant);
			ant = init_struct(ant);
			ant = init_room2(ant);
		}
		if (ant.check == 1)
			ant = path(ant);
	}
	return (ant);
}

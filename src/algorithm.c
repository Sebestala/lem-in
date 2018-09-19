/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:31:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/19 21:38:19 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static t_ptr	*ptr_room(t_ant *ant, t_room *room)
{
	int		i;
	t_ptr	*ptr1;
	t_ptr	*ptr;

	ptr1 = ant->path_end->ptr_path->room_end;
	i = 1;
	ptr = room->tube;
	while (ptr != NULL && i < room->check)
	{
		ptr = ptr->next;
		i++;
	}
	if (ptr && ptr1->id > 1 && ptr->ptr_room->last_room == -1)
	{
		room->check++;
		ptr = ptr->next;
	}
	return (ptr);
}

static t_room	*ptr_room_end(t_ant *ant)
{
	t_ptr	*ptr1;
	t_ptr	*ptr2;

	ptr1 = ant->path_end;
	ptr2 = ptr1->ptr_path->room_end;
	return (ptr2->ptr_room);
}

static t_ant	*make_ptr_path(t_ant *ant, t_room *ptr_room)
{
	t_ptr	*struct_ptr;
	t_ptr	*ptr;
	t_ptr	*ptr2;

	if (ptr_room == ant->start)
		return (ant);
	ptr = ant->path_end;
	struct_ptr = memalloc_sterr(sizeof(t_ptr), "make_ptr_path");
	if (ptr != NULL)
	{
		ptr2 = ptr->ptr_path->room_end;
		struct_ptr->back = ptr2;
		struct_ptr->id = ptr2->id + 1;
		ptr2->next = struct_ptr;
		ptr->ptr_path->room_end = struct_ptr;
	}
	else
		ptr = struct_ptr;
	struct_ptr->ptr_room = ptr_room;
	if (ptr->ptr_path->room_end->ptr_room->name != ptr_room->name)
	printf("NAME END = |%s|      NAME = |%s|\n", ptr->ptr_path->room_end->ptr_room->name, ptr_room->name);
	return (ant);
}

static t_ant	*del_ptr_path(t_ant *ant)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;
	t_ptr	*ptr3;

	ptr2 = ant->path_end;
	ptr = ptr2->ptr_path->room_end;
	ptr->ptr_room->check = 0;
	ptr3 = ptr->back;
	ptr3->next = NULL;
	ptr2->ptr_path->room_end = ptr3;
	ft_bzero(ptr, sizeof(t_ptr));
	free(ptr);
	return (ant);
}

static t_ant	*make_enter_path(t_ant *ant)
{
	t_path	*path;
	t_ptr	*struct_ptr;
	t_ptr	*struct_ptr_in_path;
	t_ptr	*ptr;

	path = memalloc_sterr(sizeof(t_path), "make_enter_path");
	struct_ptr = memalloc_sterr(sizeof(t_ptr), "make_enter_path");
	struct_ptr_in_path = memalloc_sterr(sizeof(t_ptr), "make_enter_path");
	if (ant->path == NULL)
	{
		ant->path = struct_ptr;
		ant->path_end = ant->path;
	}
	else
	{
		ptr = ant->path_end;
		path->id = ant->path_end->ptr_path->id;
		ant->path_end = struct_ptr;
		ptr->next = struct_ptr;
		struct_ptr->back = ptr;
	}
	struct_ptr->ptr_path = path;
	path->id = ant->path_end->ptr_path->id + 1;
	path->room = struct_ptr_in_path;
	path->room_end = struct_ptr_in_path;
	struct_ptr_in_path->ptr_room = ant->start;
	return (ant);
}

t_ant		*valid_path(t_ant *ant)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;

	ptr = ant->path_end;
	ptr2 = ptr->ptr_path->room;
	ant = make_enter_path(ant);
	while (ptr2 != NULL)
	{
		ant = make_ptr_path(ant, ptr2->ptr_room);
		ptr2 = ptr2->next;
	}
	ant->firewall++;
if (ant->firewall % 100 == 0)
{
printf("ID PATH  = |%d|\n", ant->firewall);
fflush(stdout);
}
	return (ant);
}

static t_ant	*on_end(t_ant *ant)
{
	ant = valid_path(ant);
	ant->start->check++;
	ant = del_ptr_path(ant);
	return (ant);
}

static t_ant	*find_end(t_ant *ant, t_ptr *ptr)
{
	while (ptr != NULL)
	{
		if (ptr->ptr_room == ant->end)
			break ;
		ptr = ptr->next;
	}
	if (ptr != NULL)
	{
		ant = make_ptr_path(ant, ptr->ptr_room);
		ant = valid_path(ant);
		ant = del_ptr_path(ant);
	}
	else
		exit_str("Error : end's room not find");
	return (ant);
}

t_ant			*deep_way(t_ant *ant)
{
	t_room	*element;
	t_ptr	*ptr;
ant->firewall = 1;
	element = ant->start;
	ant = make_enter_path(ant);
	ptr = element->tube;
	while (element != ant->start || ptr != NULL)
	{
//	printf("NAME = |%s|\n", element->name);
		ptr = element->tube;
		element->check++;
		if (element == ant->end)
		{
			ant = on_end(ant);
			element = ant->start;
			ptr = element->tube;
		}
		if (element->last_room == 1 && element != ant->start)
		{
			ant = find_end(ant, ptr);
			ant = del_ptr_path(ant);
			element = ptr_room_end(ant);
			ptr = element->tube;
			element->check++;
		}
		if (element->check > 1 && element->last_room <= 0 && ptr != NULL)
			ptr = ptr_room(ant, element);
		while (ptr == NULL)
		{
			if (element == ant->start)
				break ;
			ant = del_ptr_path(ant);
			element = ptr_room_end(ant);
			element->check++;
			ptr = ptr_room(ant, element);
		}
		if (ptr && ptr->ptr_room->check == 0 && ptr->ptr_room->tube != NULL)
		{
			ant = make_ptr_path(ant, ptr->ptr_room);
			element = ptr->ptr_room;
		}
//		if (ant->firewall % 400 == 0)
//			break ;
	}
	return (ant);
}

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

static t_room	*room_in_tab_tube(t_room *room)
{
//	printf("room_in_tab_tube\n");
	t_tab	*tab;

	tab = room->tube;
	while (tab->next)
		tab = tab->next;
	return (tab->tab[room->check % 100]);
}

static t_room	*ptr_room(t_ant *ant, t_room *room)
{
//	printf("ptr_room\n");
	t_ptr	*ptr1;
	t_room	*ptr;

	ptr1 = ant->path_end->room_end;
	room->check--;
	ptr = room_in_tab_tube(room);
	room->check++;
	if (ptr && ptr1->id > 1 && ptr->last_room == -1)
	{
		room->check++;
		ptr = ptr->next;
	}
	return (ptr);
}

static t_ant	*make_ptr_path(t_ant *ant, t_room *ptr_room)
{
//	printf("make_ptr_path   room = %s\n", ptr_room->name);
	t_ptr	*struct_ptr;
	t_ptr	*ptr2;

	if (ptr_room == ant->start)
		return (ant);
	struct_ptr = memalloc_sterr(sizeof(t_ptr), "make_ptr_path");
	if (ant->path_end != NULL)
	{
		ptr2 = ant->path_end->room_end;
		struct_ptr->back = ptr2;
		struct_ptr->id = ptr2->id + 1;
		ptr2->next = struct_ptr;
		ant->path_end->room_end = struct_ptr;
	}
	struct_ptr->ptr_room = ptr_room;
	if (ant->path_end->room_end->ptr_room->name != ptr_room->name)
	printf("NAME END = |%s|      NAME = |%s|\n", ant->path_end->room_end->ptr_room->name, ptr_room->name);
	return (ant);
}

static t_ant	*del_ptr_path(t_ant *ant)
{
//	printf("del_ptr_path\n");
	t_ptr	*ptr;
	t_ptr	*ptr3;

	ptr = ant->path_end->room_end;
	ptr->ptr_room->check = 0;
	ptr3 = ptr->back;
	ptr3->next = NULL;
	ant->path_end->room_end = ptr3;
	ft_bzero(ptr, sizeof(t_ptr));
	free(ptr);
	return (ant);
}

static t_ant	*make_enter_path(t_ant *ant)
{
//	printf("make_enter_path\n");
	t_path	*path;
	t_ptr	*struct_ptr_in_path;

	path = memalloc_sterr(sizeof(t_path), "make_enter_path");
	struct_ptr_in_path = memalloc_sterr(sizeof(t_ptr), "make_enter_path");
	if (ant->path == NULL)
	{
		ant->path = path;
		ant->path_end = ant->path;
	}
	else
	{
		path->id = ant->path_end->id;
		path->back = ant->path_end;
		ant->path_end->next = path;
		ant->path_end = path;
	}
	path->id = ant->path_end->id + 1;
	path->room = struct_ptr_in_path;
	path->room_end = struct_ptr_in_path;
	struct_ptr_in_path->ptr_room = ant->start;
	return (ant);
}

t_ant		*valid_path(t_ant *ant)
{
//	printf("valid_path\n");
	t_ptr	*ptr2;

	ptr2 = ant->path_end->room;
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
//	printf("on_end\n");
	ant = valid_path(ant);
	ant->start->check++;
	ant = del_ptr_path(ant);
	return (ant);
}

static t_ant	*find_end(t_ant *ant, t_room *ptr, t_room *element)
{
//	printf("find_end\n");
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

t_ant			*deep_way(t_ant *ant)
{
//	printf("ANT_ROOM = |%s|\n", ant->room->name);
	t_room	*element;
	t_room	*ptr;
ant->firewall = 1;
	element = ant->start;
	ant = make_enter_path(ant);
	ptr = room_in_tab_tube(element);
	while (element != ant->start || ptr != NULL)
	{
	if (element)
//	printf("\nNAME = |%s|\n", element->name);
		ptr = room_in_tab_tube(element);
	if (ptr)
//	printf("NAME2 = |%s|\n", ptr->name);
		element->check++;
		if (element == ant->end)
		{
			ant = on_end(ant);
			element = ant->start;
			ptr = room_in_tab_tube(element);
		}
		if (element->last_room == 1 && element != ant->start)
		{
			ant = find_end(ant, ptr, element);
			ant = del_ptr_path(ant);
			element = ant->path_end->room_end->ptr_room;
			ptr = room_in_tab_tube(element);
			element->check++;
		}
		if (element->check > 1 && element->last_room <= 0 && ptr != NULL)
			ptr = ptr_room(ant, element);
//	if (ptr)
//	printf("NAME2 = |%s|\n", ptr->name);
		while (ptr == NULL)
		{
			if (element == ant->start)
				break ;
			ant = del_ptr_path(ant);
			element = ant->path_end->room_end->ptr_room;
			element->check++;
			ptr = ptr_room(ant, element);
		}
		if (ptr && ptr->check == 0 && ptr->tube != NULL)
		{
			ant = make_ptr_path(ant, ptr);
			element = ptr;
		}
//		if (ant->firewall % 400 == 0)
//			break ;
	}
	return (ant);
}

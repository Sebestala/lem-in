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

static t_room	*room_in_path_room(t_ant *ant)
{
	printf("room_in_path_room\n");
	t_tab	*tab;

	tab = ant->path_end->room;
	while (tab->next)
		tab = tab->next;
	return (tab->tab[ant->path_end->room_end % 100]);
}

static t_room	*room_in_tab_tube(t_room *room)
{
//	printf("room_in_tab_tube     room enter = %s  \n", room->name);
	printf("room_in_tab_tube\n");
	t_tab	*tab;
	int		nb;

	if (!room)
		return (NULL);
	nb = room->check;
	tab = room->tube;
	while (nb > 99)
	{
		tab = tab->next;
		nb -= 100;
	}
//	printf("name = %s   check = %d  \n", room->name, room->check);
	return (tab->tab[nb]);
}

static t_room	*ptr_room(t_ant *ant, t_room *room)
{
//	printf("ptr_room   nb = %d \n", ant->path_end->room_end);
	printf("ptr_room\n");
	t_room	*ptr;

	ptr = room_in_tab_tube(room);
//	if (ptr)
//	printf("room = %s    nb = %d\n", ptr->name, ant->path_end->room_end);
	if (ptr && ant->path_end->room_end > 1 && ptr->last_room == -1)
	{
		room->check++;
		ptr = ptr->next;
	}
//	if (ptr)
//	printf("room = %s\n", ptr->name);
	return (ptr);
}

static t_ant	*make_ptr_path(t_ant *ant, t_room *ptr_room)
{
	printf("make_ptr_path\n");
//	printf("				make_ptr_path   room = %s   check = %d\n", ptr_room->name, ptr_room->check);
	t_tab	*struct_ptr;
	t_tab	*tab;

	if (ptr_room == ant->start)
		return (ant);
	tab = ant->path_end->room;
	ant->path_end->room_end++;
	if (ant->path_end->room_end != 0 && ant->path_end->room_end % 100 == 0)
	{
		struct_ptr = memalloc_sterr(sizeof(t_tab), "make_ptr_path");
		while (tab->next)
			tab = tab->next;
		tab->next = struct_ptr;
	}
	while (tab->next)
		tab = tab->next;
	tab->tab[ant->path_end->room_end % 100] = ptr_room;
	return (ant);
}

static t_ant	*del_ptr_path(t_ant *ant)
{
	printf("del_ptr_path\n");
	t_room	*room;
	t_tab	*tab;
	t_tab	*tab2;

	tab = ant->path_end->room;
	while (tab->next)
		tab = tab->next;
	room = tab->tab[ant->path_end->room_end % 100];
	room->check = 0;
	tab->tab[ant->path_end->room_end % 100] = 0;
	ant->path_end->room_end--;
	if (ant->path_end->room_end % 100 == 99)
	{
		tab2 = ant->path_end->room;
		while (tab2->next->next != NULL)
			tab2 = tab2->next;
		tab2->next = NULL;
		memdel_zero(tab, sizeof(t_tab));
	}
	return (ant);
}

static t_ant	*make_enter_path(t_ant *ant)
{
	printf("make_enter_path\n");
	t_path	*path;
	t_tab	*struct_ptr_in_path;

	path = memalloc_sterr(sizeof(t_path), "make_enter_path");
	struct_ptr_in_path = memalloc_sterr(sizeof(t_tab), "make_enter_path");
	if (ant->path == NULL)
	{
		ant->path = path;
		ant->path_end = path;
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
	struct_ptr_in_path->tab[0] = ant->start;
	return (ant);
}

t_ant		*valid_path(t_ant *ant)
{
	printf("valid_path\n");
	t_tab	*tab;
	t_room	*room;
	int		i;

	tab = ant->path_end->room;
	ant = make_enter_path(ant);
	while (tab)
	{
		i = 0;
		while (tab->tab[i])
		{
			room = tab->tab[i];
			ant = make_ptr_path(ant, room);
			i++;
		}
		tab = tab->next;
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
	printf("on_end\n");
	ant = valid_path(ant);
	ant->start->check++;
	ant = del_ptr_path(ant);
	return (ant);
}

static t_ant	*find_end(t_ant *ant, t_room *ptr, t_room *element)
{
	printf("find_end\n");
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
//	if (element)
//	printf("\n				NAME = |%s|\n", element->name);
		ptr = room_in_tab_tube(element);
		if (element->check > 1 && element->last_room <= 0 && ptr != NULL)
		ptr = ptr_room(ant, element);
//	if (ptr)
//	printf("				NAME2 = |%s|\n", ptr->name);
		element->check++;
		if (ptr && ptr->check == 0 && ptr->tube != NULL)
		{
			ant = make_ptr_path(ant, ptr);
			element = ptr;
		}
		if (element == ant->end)
		{
			ant = on_end(ant);
			element = ant->start;
			ptr = room_in_tab_tube(element);
		}
		else if (element->last_room == 1 && element != ant->start)
		{
			ant = find_end(ant, ptr, element);
			ant = del_ptr_path(ant);
			element = room_in_path_room(ant);
			ptr = room_in_tab_tube(element);
//			element->check++;
		}
//	if (ptr)
//	printf("				NAME2 = |%s|\n", ptr->name);
		while (ptr == NULL)
		{
		printf("QQQ\n");
			if (element == ant->start)
				break ;
			ant = del_ptr_path(ant);
			element = room_in_path_room(ant);
//			element->check++;
//	if (element)
//	printf("ELEMENT = |%s|\n", element->name);
			ptr = ptr_room(ant, element);
//	if (ptr)
//	printf("PTR = |%s|\n", ptr->name);
		}
//		if (ant->firewall % 400 == 0)
//			break ;
	}
//	printf("		ANT->LAST ROOM = %d\n", ant->start->last_room);
	return (ant);
}

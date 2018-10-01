/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:31:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/10/01 19:51:45 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant			*make_ptr_path(t_ant *ant, t_room *ptr_room)
{
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

t_ant			*del_ptr_path(t_ant *ant)
{
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

static int		check_nb_room_in_path(t_ant *ant)
{
	if (ant->path_end->id > 100 && ant->path_end->room_end > 5)
		return (1);
	if (ant->path_end->id > 50 && ant->path_end->room_end > 7)
		return (1);
	if (ant->path_end->id > 20 && ant->path_end->room_end > 10)
		return (1);
	if (ant->path_end->id >= 0 && ant->path_end->room_end > 15)
		return (1);
	if (ant->path_end->id < 1)
		return (0);
	return (0);
}

static	void	deep_way2(t_ant *ant, t_room **element, t_room **ptr)
{
	if ((*element)->check > 1 && (*element)->last_room <= 0 && *ptr != NULL)
		*ptr = ptr_room(ant, *element);
	(*element)->check++;
	if (*ptr && (*ptr)->check == 0 && (*ptr)->tube != NULL)
	{
		ant = make_ptr_path(ant, *ptr);
		*element = *ptr;
	}
	if (*element == ant->end)
	{
		ant = on_end(ant);
		*element = ant->start;
		*ptr = room_in_tab_tube(*element);
	}
	else if ((*element)->last_room == 1 && *element != ant->start)
	{
		ant = find_end(ant, *ptr, *element);
		ant = del_ptr_path(ant);
		*element = room_in_path_room(ant);
		*ptr = room_in_tab_tube(*element);
	}
}

t_ant			*deep_way(t_ant *ant)
{
	t_room	*element;
	t_room	*ptr;

	element = ant->start;
	ant = make_enter_path(ant);
	ptr = room_in_tab_tube(element);
	while (element != ant->start || ptr != NULL)
	{
		ptr = room_in_tab_tube(element);
		deep_way2(ant, &element, &ptr);
		while (ptr == NULL || check_nb_room_in_path(ant))
		{
			if (element == ant->start)
				break ;
			ant = del_ptr_path(ant);
			element = room_in_path_room(ant);
			ptr = ptr_room(ant, element);
		}
		if (ant->path_end->id > 999998)
			break ;
	}
	return (ant);
}

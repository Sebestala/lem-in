/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:45:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:49:08 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void		delete_last_path2(t_ptr *ptr2)
{
	t_ptr	*ptr;

	while (ptr2 != NULL)
	{
		ptr = ptr2;
		ptr2 = ptr2->next;
		memdel_zero(ptr, sizeof(t_ptr));
	}
}

void			delete_last_path(t_ant *ant, t_ptr *ptr1)
{
	t_ptr	*ptr2;
	t_path	*path;

	ptr2 = ptr1->ptr_path->id_path;
	delete_last_path2(ptr1->ptr_path->id_path);
	delete_last_path2(ptr1->ptr_path->room);
	if (ptr1->back != NULL)
	{
		ptr2 = ptr1->back;
		ptr2->next = NULL;
	}
	else
		ant->path = NULL;
	path = ptr1->ptr_path;
	ant->path_end = ant->path_end->back;
	memdel_zero(ptr1, sizeof(t_ptr));
	memdel_zero(path, sizeof(t_path));
}

void		delete_last_poss(t_ant *ant)
{
	t_ptr	*ptr2;
	t_ptr	*ptr3;
	t_poss	*poss;
	t_poss	*poss2;

	poss = ant->poss;
	while (poss->next != NULL)
	{
		poss2 = poss;
		poss = poss->next;
	}
	poss2->next = NULL;
	ptr2 = poss->id_path;
	while (ptr2 != NULL)
	{
		ptr3 = ptr2;
		ptr2 = ptr2->next;
		memdel_zero(ptr3, sizeof(t_ptr));
	}
	memdel_zero(poss, sizeof(t_poss));
}

static void	delete_all_poss(t_ant *ant)
{
	t_ptr	*ptr2;
	t_ptr	*ptr3;
	t_poss	*poss;
	t_poss	*poss2;

	poss = ant->poss;
	while (poss)
	{
		poss2 = poss->next;
		ptr2 = poss->id_path;
		while (ptr2 != NULL)
		{
			ptr3 = ptr2;
			ptr2 = ptr2->next;
			memdel_zero(ptr3, sizeof(t_ptr));
		}
		memdel_zero(poss, sizeof(t_poss));
		poss = poss2;
	}
}

static void	delete_all_pawn(t_ant *ant)
{
	t_pawn	*pawn;
	t_pawn	*pawn2;

	pawn = ant->pawn;
	while (pawn)
	{
		pawn2 = pawn->next;
		memdel_zero(pawn, sizeof(t_pawn));
		pawn = pawn2;
	}
}

static void	delete_all_room(int i, t_room *room, t_ptr *ptr2)
{
	t_ptr	*ptr3;
	t_room	*room2;

	while (room)
	{
		i = 2;
		ptr2 = room->id_path;
		while (i > 0)
		{
			while (ptr2)
			{
				ptr3 = ptr2;
				ptr2 = ptr2->next;
				memdel_zero(ptr3, sizeof(t_ptr));
			}
			i--;
			ptr2 = room->tube;
		}
		room2 = room;
		room = room->next;
		ft_strdel(&room2->name);
		memdel_zero(room2, sizeof(t_room));
	}
}

void		delete_lemin(t_ant *ant)
{
	t_ptr	*ptr;

	delete_all_poss(ant);
	ptr =  ant->path;
	while (ptr->next != NULL)
		ptr = ptr->next;
	while (ptr != NULL)
	{
		ptr = ptr->back;
		delete_last_path(ant, ant->path_end);
	}
	delete_all_pawn(ant);
	delete_all_room(2, ant->room, NULL);
	ft_strdel(&ant->line);
	memdel_zero(ant->tab_id, ((ant->nb_path * 50) * sizeof(int)));
	memdel_zero(ant, sizeof(t_ant));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:45:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/28 19:17:13 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void	delete_all_path(t_ant *ant, int i, int j)
{
	t_tab2	*tab2;
	t_tab2	*tab3;
	t_path	*path;

	tab3 = NULL;
	while (ant->path[i])
	{
		j = 0;
		tab2 = ant->path[i];
		if (tab3)
			memdel_zero(tab3, sizeof(t_tab2));
		while (tab2->tab2[j])
		{
			path = tab2->tab2[j];
			delete_last_path2(path->room);
			ft_strdel(&path->id_path);
			memdel_zero(path, sizeof(t_path));
			j++;
		}
		i++;
		tab3 = tab2;
	}
	memdel_zero(tab3, sizeof(t_tab2));
	ant->path_end = NULL;
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

static void	delete_all_room(t_room *room, t_tab *ptr2)
{
	t_tab	*ptr3;
	t_room	*room2;

	while (room)
	{
		ptr2 = room->tube;
		while (ptr2)
		{
			ptr3 = ptr2;
			ptr2 = ptr2->next;
			memdel_zero(ptr3, sizeof(t_tab));
		}
		room2 = room;
		room = room->next;
		ft_strdel(&room2->name);
		ft_strdel(&room2->id_path);
		memdel_zero(room2, sizeof(t_room));
	}
}

void		delete_lemin(t_ant *ant)
{
	memdel_zero(ant->verif_path_answer, sizeof(int) * ant->best_poss->nb_path);
	delete_all_poss(ant);
	delete_all_path(ant, 0, 0);
	delete_all_pawn(ant);
	delete_all_room(ant->room, NULL);
	ft_strdel(&ant->line);
	ft_strdel(&ant->tab_id);
	memdel_zero(ant, sizeof(t_ant));
}

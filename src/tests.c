/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:24:11 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/30 19:57:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void			fct_test(t_ant *ant, int i)
{
	t_tab	*ptr;
	t_room	*room;
	t_room	*room0;

	room0 = ant->room;
	ft_printf("\n ANT  =	%d \n", ant->nb_ant);
	while (room0 != NULL && ant->room_end->id < 50)
	{
		ft_printf(" NAME =	%s   LAST ROOM = %d\n", room0->name,
				room0->last_room);
		ptr = room0->tube;
		while (ptr != NULL)
		{
			i = 0;
			while (ptr->tab[i])
			{
				room = ptr->tab[i++];
				ft_printf("	%s---%s\n", room0->name, room->name);
			}
			ptr = ptr->next;
		}
		ft_printf("\n");
		room0 = room0->next;
	}
	fct_test1(ant);
}

void			fct_test2(t_ant *ant)
{
	t_ptr	*ptr;
	t_poss	*poss;

	poss = ant->poss;
	ft_printf("\n				POSSIBILITY\n");
	while (poss != NULL && ant->poss_end->id_poss < 300)
	{
		ptr = poss->id_path;
		ft_printf("\n	POSS N°%d	NB PATH = %d	POWER = %d\n\n	 id paths ="
		, poss->id_poss, poss->nb_path, poss->total_power);
		while (ptr != NULL)
		{
			ft_printf(" {%d} ", ptr->id);
			ptr = ptr->next;
		}
		ft_printf("\n\n");
		poss = poss->next;
	}
	ft_printf("  BEST POSSIBILITY ===>    ID N°%d	NB PATH = %d	TOTAL POWER"
	"= %d\n", ant->best_poss->id_poss, ant->best_poss->nb_path,
	ant->best_poss->total_power);
	ft_printf("\n\n			-----------------------------\n");
}

static void		fct_test1_1(t_path *path, t_tab *tab, int l, int i)
{
	t_room	*room;

	ft_printf("\n\n	PATH %d   POWER = %d   ID = ", path->id, path->power);
	while (path->id_path[i])
	{
		if (path->id_path[i] == '1')
			ft_printf("{%d} ", i);
		i++;
	}
	ft_printf("\n\n");
	tab = path->room;
	while (tab->tab[l])
	{
		i = 0;
		room = tab->tab[l];
		ft_printf("	%s   id = ", room->name);
		while (room->id_path[i])
		{
			if (room->id_path[i] == '1')
				ft_printf("{%d} ", i);
			i++;
		}
		l++;
		ft_printf("\n\n");
	}
}

void			fct_test1(t_ant *ant)
{
	t_tab2	*tab2;
	int		k;
	int		l;

	k = 0;
	l = 0;
	ft_printf("START =	name = %s\n", ant->start->name);
	ft_printf("END   =	name = %s\n", ant->end->name);
	ft_printf("\n\n			-----------------------------\n");
	ft_printf("\n				   PATHS\n");
	while (ant->path[k] && ant->nb_path < 100)
	{
		tab2 = ant->path[k];
		l = 0;
		while (tab2->tab2[l])
		{
			fct_test1_1(tab2->tab2[l], NULL, l, 0);
			l++;
		}
		k++;
	}
	ft_printf("\n			-----------------------------\n");
	fct_test2(ant);
}

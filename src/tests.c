/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:24:11 by sgarcia           #+#    #+#             */
/*   Updated: 2018/10/01 22:02:07 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		fct_test0_1(t_room *room0, int i)
{
	t_tab	*ptr;
	t_room	*room;

	ft_printf(" {-YELLOW-LIGHT}NAME =	{-CYAN}%s  {-RED} LAST ROOM = %d"
	"\033[0m\n", room0->name, room0->last_room);
	ptr = room0->tube;
	while (ptr != NULL)
	{
		i = 0;
		while (ptr->tab[i])
		{
			rainbow(i);
			room = ptr->tab[i++];
			ft_printf("	%s---%s\n", room0->name, room->name);
		}
		ptr = ptr->next;
	}
	ft_printf("\n");
}

void			fct_test(t_ant *ant, int i)
{
	t_room	*room0;

	room0 = ant->room;
	ft_printf("\n	\033[0m		-----------------------------\n\n			   "
	"	   {-LINE-LIGHT}TUBE\n\n\n\033[0m{-LIGHT-YELLOW} ANT  =	{-GREY}%d \n"
	, ant->nb_ant);
	while (room0 != NULL && ant->room_end->id < 50)
	{
		fct_test0_1(room0, i);
		room0 = room0->next;
	}
	fct_test1(ant);
}

static void		fct_test1_2(t_path *path, int i)
{
	ft_printf("\n\n	{-BLUE-LINE-LIGHT}PATH %d\033[0m   {-LIGHT-PINK}POWER ="
	"{-YELLOW} %d  {-GREEN} ID = ", path->id, path->power);
	while (path->id_path[i])
	{
		if (path->id_path[i] == '1')
			ft_printf("\033[0m{-GREEN}{{-YELLOW}%d{-GREEN}} ", i);
		i++;
	}
	ft_printf("\n\n");
}

static void		fct_test1_1(t_path *path, t_tab *tab, int l, int i)
{
	t_room	*room;

	fct_test1_2(path, i);
	tab = path->room;
	while (tab->tab[l])
	{
		i = 0;
		rainbow(l);
		room = tab->tab[l];
		ft_printf("	%s   id = ", room->name);
		while (room->id_path[i])
		{
			if (room->id_path[i] == '1')
				ft_printf("\033[0m{-GREEN}{{-YELLOW}%d{-GREEN}} ", i);
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
	ft_printf("{-LINE-GREEN-LIGHT-ITALIC}START name ---> %s", ant->start->name);
	ft_printf("\nEND name ---> %s\n\033[0m", ant->end->name);
	ft_printf("\n\n			-----------------------------\n");
	ft_printf("\n				   {-LINE-LIGHT}PATHS\n");
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
	ft_printf("\n	\033[0m		-----------------------------\n");
	fct_test2(ant);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:23:31 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/29 16:23:34 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void			put_str_id_path2(t_ant *ant, t_room *room, int i)
{
	while (room)
	{
		i = 0;
		room->id_path = ft_strnew(ant->nb_path + 2);
		while (i <= ant->nb_path + 1)
			room->id_path[i++] = '0';
		room = room->next;
	}
}

void				put_str_id_path(t_ant *ant, t_room *room, int i, int j)
{
	t_path	*path;
	t_tab2	*tab;
	int		k;

	put_str_id_path2(ant, room, i);
	while (ant->path[i])
	{
		tab = ant->path[i];
		j = 0;
		while (tab->tab2[j])
		{
			k = 0;
			path = tab->tab2[j];
			path->id_path = ft_strnew(ant->nb_path + 2);
			while (k <= ant->nb_path + 1)
				path->id_path[k++] = '0';
			j++;
		}
		i++;
	}
}

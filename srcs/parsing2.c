/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 23:47:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/13 00:06:22 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant	init_path(t_ant ant, char *str)
{
	if (verif_name(ant, ant.room->name) != 1)
		ant.error++;
	if (!(ant.room->path = (t_path *)malloc(sizeof(t_path))))
		ant.error++;
	if (!(ant.room->path->name = (char *)malloc(ft_strlen(str) * sizeof(char))))
	{
		free(ant.room);
		ant.error++;
	}
	ft_bzero(ant.room->path, sizeof(t_room));




jen suis la, il va falloir faire un lst_add pour path mais avec une autre technque cette fois






	if (!ant.lst)
	{
		ant.lst = ant.room;
		ant.begin = ant.lst;
	}
	else
		ant.lst->next = ant.room;
	ant.room->next = NULL;
	ant.lst = ant.room;
	ant.room->name = ft_strncpy(ant.room->name, ant.line, ant.i);
	ant = verif_name(ant, ant.room->name);
	return (ant);



	return (ant);
}

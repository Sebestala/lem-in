/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:10:47 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/17 16:31:34 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant	init_struct(t_ant ant)
{
	if (ant.line[ant.i] && ant.line[ant.i] == 'L')
		exit_str("Error : enter is incorrect");
	while (ant.line[ant.i] && ant.line[ant.i] != ' ')
		ant.i++;
	if (!(ant.room = (t_room *)malloc(sizeof(t_room))))
		exit_str("Error : dynamic allocation problem in init_struct");
	if (!(ant.room->name = (char *)malloc(ant.i * sizeof(char))))
	{
		free(ant.room);
		exit_str("Error : dynamic allocation problem in init_struct");
	}
	ft_bzero(ant.room, sizeof(t_room));
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
	if (verif_name(ant, ant.room->name) > 0)
		exit_str("Error : dynamic allocation problem in init_struct");
	return (ant);
}

static t_ant		init_room2(t_ant ant)
{
	ant.i++;
	if (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.j++;
	while (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.i++;
	if (ant.line[ant.i] && ant.line[ant.i] == ' ')
		ant.j++;
	if (ant.line[ant.i] && ant.line[ant.i] == ' ')
		ant.i++;
	if (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.j++;
	while (ant.line[ant.i] && ant.line[ant.i] >= '0' && ant.line[ant.i] <= '9')
		ant.i++;
	if (ant.line[ant.i] != '\0' || ant.j != 3)
		exit_str("Error : room enter is incorrect");
	return (ant);
}

static t_ant		command(t_ant ant)
{
	if (ft_strcmp(ant.line, "##start"))
	{
		get_next_line(0, &ant.line, 0);
		ant.i = 0;
		ant.j = 0;
		ant = comment(ant);
		ant = init_struct(ant);
		ant = init_room2(ant);
		ant.start = ant.room;
		get_next_line(0, &ant.line, 0);
	}
	if (ft_strcmp(ant.line, "##end"))
	{
		get_next_line(0, &ant.line, 0);
		ant.i = 0;
		ant.j = 0;
		ant = comment(ant);
		ant = init_struct(ant);
		ant = init_room2(ant);
		ant.end = ant.room;
		get_next_line(0, &ant.line, 0);
	}
	return (ant);
}

static t_ant		path(t_ant ant)
{
	char	*str1;
	char	*str2;

	while (ant.line[ant.i] && ant.line[ant.i] != '-')
		ant.i++;
	str1 = ft_memalloc(ant.i);
	while (ant.line[ant.j] && ant.line[ant.j] != '-')
		str1[ant.j++] = ant.line[ant.j];
	ant.i++;
	ant.j++;
	while (ant.line[ant.i])
		ant.i++;
	str2 = ft_memalloc(ant.i);
	while (ant.line[ant.j] && ant.line[ant.j] != '-')
		str2[ant.j++] = ant.line[ant.j];
	ant.room = ant.begin;
	while (ant.room)
	{
		if (ft_strcmp(ant.room->name, str1) == 0)
			init_path(ant, str1);


	}
	return (ant);
}

t_ant				init_room(t_ant ant)
{
	while (get_next_line(0, &ant.line, 0))
	{
		ant = command(ant);
		ant.i = 0;
		ant.j = 0;
		ant = comment(ant);
		if (is_str_on(ant.line, " "))
		{
			ant = init_struct(ant);
			ant = init_room2(ant);
		}
		else
			ant = path(ant);

	}
//	if (ant.error > 0)//free le tout ou utiliser le return error de fbabin

	return (ant);
}

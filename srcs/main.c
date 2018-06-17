/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 22:28:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/17 16:31:27 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant	init_ant(t_ant ant)
{
	ant.i = 0;
	ant.j = 0;
	ant.nb_ant = 0;
	return (ant);
}

int				verif_name(t_ant ant, char *str)
{
	int		i;

	i = 0;
	ant.room = ant.begin;
	while (ant.room && ant.room->next != NULL)
	{
		if (ft_strcmp(ant.room->name, str) == 0)
			i++;
		ant.room = ant.room->next;
	}
	return (i);
}

t_ant			comment(t_ant ant)
{
	while (ant.line[0] && ant.line[0] == '#' && ant.line[1] != '#' &&
			get_next_line(0, &ant.line, 0))
	{
		ant.i = 0;
		ant.j = 0;
		ft_putstr(ant.line);
	}
	return (ant);
}

static t_ant	is_valid(t_ant ant)
{
	get_next_line(0, &ant.line, 1);
	ant = comment(ant);
	if (!ant.line)
		exit_str("Error : enter incorrect");
	while (ant.line[ant.i])
	{
		if (ant.line[ant.i] < '0' || ant.line[ant.i] > '9')
			exit_str("Error : number ants is incorrect");
		ant.i++;
	}
	ant.nb_ant = atoi_my(ant.line);
	ant = init_room(ant);
	get_next_line(0, &ant.line, 0);


	return (ant);
}

int				main(void)
{
	t_ant	ant;

	ant = is_valid(ant);



	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 22:28:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/01 19:32:14 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ptr_back(t_ptr *ptr)
{
	t_ptr	*element;

	element = ptr;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		ptr->back = element;
		element = ptr;
		ptr = ptr->next;
	}
}

t_ant	init_ant(t_ant ant)
{
	ant.i = 0;
	ant.j = 0;
	ant.check = 0;
	return (ant);
}

t_ant			comment(t_ant ant)
{
	while (ant.line && ant.line[0] && ant.line[0] == '#' && ant.line[1] != '#')
	{
		ant.i = 0;
		ant.j = 0;
		ft_putendl(ant.line);
		get_next_line(0, &ant.line, 0);
	}
	return (ant);
}

static t_ant	is_valid(t_ant ant)
{
	ant = init_ant(ant);
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
	ptr_back(ant.room);
	if (ant.start->tube == NULL || ant.end->tube == NULL)
		exit_str("Error : no path possible");
	while (ant.end->tube != NULL)
	{
		ant.end->tube->id = 1;
		ant.end->tube = ant.end->tube->next;
	}
	ant = init_ant(ant);
	write (1, "\n", 1);
	return (ant);
}

int				main(void)
{
	t_ant	ant;

	ant.nb_ant = 0;
	ant = is_valid(ant);
	if (ant.start == ant.end)
		exit_str("Error : start room and end room should'nt be the same room");
	ant = find_final_room(ant);
	ant = deep_way(ant);
	ant = put_id_path(ant);
	ant = init_ant(ant);
	ant = possibility(ant);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 22:28:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/23 20:58:30 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	if (ant.start->tube == NULL || ant.end->tube == NULL)
		exit_str("Error : no path possible");
	ant = find_final_room(ant);
	ant = init_ant(ant);
	write (1, "\n", 1);
	return (ant);
}

static	void	verif(t_ant ant)
{
	t_ptr	*ptr;

	if (!ant.start)
		exit_str("Error : there is no start room");
	if (!ant.end)
		exit_str("Error : there is no end room");
	if (ant.start == ant.end)
		exit_str("Error : start room and end room should'nt be the same room");
	ptr = NULL;
	while (ant.room != NULL)
	{
		ptr = ant.room;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			if (!ft_strcmp(ant.room->ptr_room->name, ptr->ptr_room->name))
				exit_str("Error : two rooms have the same name");
		}
		ant.room = ant.room->next;
	}
}

int				main(void)
{
	t_ant	ant;

	ft_bzero(&ant, sizeof(t_ant));
	ant = is_valid(ant);
	verif(ant);
// j4en suis la
	ant = deep_way(ant);
	ant = put_id_path(ant);
	ant = init_ant(ant);
	ant = possibility(ant);

	return (0);
}

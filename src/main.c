/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 22:28:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/19 19:45:46 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_ant			*init_ant(t_ant *ant)
{
	ant->i = 0;
	ant->j = 0;
	return (ant);
}

t_ant			*comment(t_ant *ant)
{
	while (ant->line && ant->line[0]
	&& ant->line[0] == '#' && ant->line[1] != '#')
	{
		ant = init_ant(ant);
		ft_putendl(ant->line);
		get_next_line(0, &ant->line);
		ft_putendl(ant->line);
	}
	return (ant);
}

static t_ant		*is_valid(t_ant *ant)
{
	ant = init_ant(ant);
	get_next_line(0, &ant->line);
	ft_putendl(ant->line);
	ant = comment(ant);
	if (!ant->line)
		exit_str("Error : enter incorrect");
	while (ant->line[ant->i])
	{
		if (ant->line[ant->i] < '0' || ant->line[ant->i] > '9')
			exit_str("Error : number ants is incorrect");
		ant->i++;
	}
	ant->nb_ant = atoi_my(ant->line);
	if (ant->nb_ant <= 0)
		exit_str("Error : number ant must be more higher than 0");
	ant = init_room(ant);
	ant = init_ant(ant);
	return (ant);
}

static t_ant		*verif(t_ant *ant)
{
	t_room	*ptr;
	t_room	*ptr2;

	if (!ant->start)
		exit_str("Error : there is no start room");
	if (!ant->end)
		exit_str("Error : there is no end room");
	if (ant->start == ant->end)
		exit_str("Error : start room and end room should'nt be the same room");
	if (ant->start->tube == NULL || ant->end->tube == NULL)
		exit_str("Error : no path possible");
	ant = find_final_room(ant);
	ptr2 = ant->room;
	while (ptr2 != NULL)
	{
		ptr = ptr2;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			if (!ft_strcmp(ptr2->name, ptr->name))
				exit_str("Error : two rooms have the same name");
		}
		ptr2 = ptr2->next;
	}
	ant = init_ant(ant);
	return (ant);
}

int				main(void)
{
	t_ant	*ant;

	ant = memalloc_sterr(sizeof(t_ant), "main");
	printf("IS VALID\n");
	fflush(stdout);
	ant = is_valid(ant);
	printf("VERIF\n");
	fflush(stdout);
	ant = verif(ant);
	printf("DEEP WAY\n");
	fflush(stdout);
	ant = deep_way(ant);
	delete_last_path(ant, ant->path_end);
	ant->nb_path = ant->path_end->id;
	printf("PUT ID PATH   nb = %d\n", ant->nb_path);
	fflush(stdout);
	ant = put_id_path(ant);
//	fct_test1(ant);
	printf("POSSIBILITY\n");
	fflush(stdout);
	if (!ant->path)
		exit_str("Error : no path possible");
	ant = possibility(ant);
	printf("CHOOSE BEST POSS\n");
	fflush(stdout);
	delete_last_poss(ant);
	ant = choose_best_poss(ant);
	printf("BEGIN ANSWER\n");
	fflush(stdout);
	ant = begin_answer(ant);
	printf("ANSWER\n");
	fflush(stdout);
	ant = init_ant(ant);
	ant = answer(ant);
	write(1, "\n", 1);
//	fct_test(ant);
//	fct_test1(ant);
//	fct_test2(ant);
//	fct_test3(ant);
	delete_lemin(ant);

	return (0);
}

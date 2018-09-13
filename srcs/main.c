/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 22:28:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:48:40 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
static void		fct_test(t_ant *ant)
{
	t_ptr	*ptr;

	printf("ANT  =	%d \n", ant->nb_ant);
	fflush(stdout);
	while (ant->room != NULL)
	{
		printf("NAME =	%s    LAST ROOM = %d\n", ant->room->ptr_room->name, ant->room->ptr_room->last_room);
		fflush(stdout);
		ptr = ant->room->ptr_room->tube;
		while (ptr != NULL)
		{
			printf("	%s---%s\n", ant->room->ptr_room->name, ptr->ptr_room->name);
			fflush(stdout);
			ptr = ptr->next;
		}
		ant->room = ant->room->next;
	}
	ant = init_ant(ant);
	printf("START	name = %s \n", ant->start->name);
	fflush(stdout);
	printf("END	name = %s \n", ant->end->name);
	fflush(stdout);

}
*/
t_ant			*init_ant(t_ant *ant)
{
/*	ant->poss = ant->poss_begin;
	ant->path = ant->path_begin;
	ant->room = ant->room_begin;
	ant->pawn = ant->pawn_begin;
*/	ant->i = 0;
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
	}
	return (ant);
}

static t_ant		*is_valid(t_ant *ant)
{
	ant = init_ant(ant);
	get_next_line(0, &ant->line);
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
	t_ptr	*ptr;
	t_ptr	*ptr2;

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
			if (!ft_strcmp(ptr2->ptr_room->name, ptr->ptr_room->name))
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
	ant = is_valid(ant);
	ant = verif(ant);
	printf("\n\n\n		||||||DEEP WAY||||||\n\n\n\n");
	fflush(stdout);
	ant = deep_way(ant);
	delete_last_path(ant, ant->path);
	printf("\n\n\n		||||||PUT ID PATH||||||\n\n\n\n");
	fflush(stdout);
	ant = put_id_path(ant);
	if (!ant->path)
		exit_str("Error : no path possible");
	printf("\n\n\n		||||||POSSIBILITY||||||\n\n\n\n");
	fflush(stdout);
	ant = possibility(ant);
	delete_last_poss(ant);
//fct_test1(ant);
//fct_test2(ant);
	printf("\n\n\n		||||||CHOOSE BEST POSS||||||\n\n\n\n");
	fflush(stdout);
	ant = choose_best_poss(ant);
	printf("\n\n\n		||||||BEGIN ANSWER||||||\n\n\n\n");
	fflush(stdout);
	ant = begin_answer(ant);
	printf("\n\n\n		||||||ANSWER||||||\n\n\n\n");
	fflush(stdout);
ant = init_ant(ant);
//fct_test3(ant);
	ant = answer(ant);
	write(1, "\n", 1);
	delete_lemin(ant);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:45:21 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:48:54 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant			*choose_best_poss(t_ant *ant)
{
printf("choose_best_poss    algorithm4\n");
fflush(stdout);
	int		best;
	int		total;
	t_poss	*poss;

	best = 0;
	total = 0;
	poss = ant->poss;
	while (poss != NULL)
	{
		total = ((poss->total_power + ant->nb_ant) / poss->nb_path);
		if (((poss->total_power + ant->nb_ant) % poss->nb_path) > 0)
			total++;
		if (best == 0 || total <= best)
		{
			ant->best_poss = poss;
			best = total;
		}
		poss = poss->next;
	}
	ant = init_ant(ant);
	ant->i++;
	return (ant);
}

static t_ant	*begin_answer2(t_ant *ant)
{
	t_pawn		*pawn;
	t_ptr		*element;
	int			best;

	pawn = ant->pawn;
	element = ant->best_poss->id_path;
	best = element->ptr_path->power;
	while (pawn->next != NULL)
		pawn = pawn->next;
	while (element != NULL)
	{
		if (best > element->ptr_path->power)
			best = element->ptr_path->power;
		element = element->next;
	}
	while (pawn != NULL)
	{
		element = ant->best_poss->id_path;
		while (element != NULL && best != element->ptr_path->power)
		{
			element = element->next;
			if (!element)
			{
				best++;
				element = ant->best_poss->id_path;
			}
		}
		element->ptr_path->power++;
		pawn->path = element->ptr_path;
		pawn = pawn->back;
	}
	return (ant);
}

t_ant			*begin_answer(t_ant *ant)
{
	t_pawn		*pawn;
	t_pawn		*element;

	element = NULL;
	while (ant->i <= ant->nb_ant)
	{
		pawn = memalloc_sterr(sizeof(t_pawn), "begin_answer");
		if (element)
		{
			element->next = pawn;
			pawn->back = element;
		}
		else
//		{
			ant->pawn = pawn;
//			ant->pawn_begin = pawn;
//		}
		element = pawn;
		element->id_pawn = ant->i;
		pawn = pawn->next;
		ant->i++;
	}
	ant->i = 1;
	ant = begin_answer2(ant);
	return (ant);
}

static t_ant	*answer2(t_ant *ant, t_pawn *pawn)
{
	int		i;
	t_ptr	*ptr;

	ptr = pawn->path->room;
	i = 1;
	write(1, "L", 1);
	ft_putnbr(pawn->id_pawn);
	write(1, "-", 1);
	while (i <= pawn->check)
	{
		ptr = ptr->next;
		i++;
	}
	ft_putstr(ptr->ptr_room->name);
	if (ant->i != ant->best_poss->nb_path)
		write(1, " ", 1);
	if (ptr->ptr_room == ant->end)
		pawn->check = -1;
	return (ant);
}

t_ant			*answer(t_ant *ant)
{
	t_pawn		*pawn;

	pawn = ant->pawn;
	while (1)
	{
		ant->i = 0;
		while (pawn != NULL)
		{
			if (pawn->check == 0)
			{
				ant->i++;
				pawn->check++;
			}
			else if (pawn->check > 0)
				pawn->check++;
			if (pawn->check > 0)
				answer2(ant, pawn);
			if (ant->i >= ant->best_poss->nb_path)
				break ;
			pawn = pawn->next;
		}
		pawn = ant->pawn;
		if (finish(ant))
			break ;
		write(1, "\n", 1);
	}
	return (ant);
}

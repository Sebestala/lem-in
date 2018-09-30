/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:23:48 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/29 16:26:35 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void		begin_answer3(t_ant *ant, t_ptr *elem, t_pawn *pawn, int best)
{
	while (pawn != NULL)
	{
		elem = ant->best_poss->id_path;
		while (elem != NULL && best != elem->ptr_path->power)
		{
			elem = elem->next;
			if (!elem)
			{
				best++;
				elem = ant->best_poss->id_path;
			}
		}
		elem->ptr_path->power++;
		pawn->path = elem->ptr_path;
		pawn = pawn->back;
	}
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
	begin_answer3(ant, element, pawn, best);
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
			ant->pawn = pawn;
		element = pawn;
		element->id_pawn = ant->i;
		pawn = pawn->next;
		ant->i++;
	}
	ant->i = 1;
	ant = begin_answer2(ant);
	return (ant);
}

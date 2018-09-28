
#include "../includes/lem-in.h"

static void		begin_answer3(t_ant *ant, t_ptr *element, t_pawn *pawn, int best)
{
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

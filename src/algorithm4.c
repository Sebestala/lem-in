/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:45:21 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/30 14:58:03 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_ant			*choose_best_poss(t_ant *ant)
{
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
	ant->verif = memalloc_sterr((sizeof(int) * ant->best_poss->nb_path),
			"choose_best_poss");
	return (ant);
}

static int		verif_answer(t_ant *ant, int i, int j)
{
	while (j < ant->best_poss->nb_path && ant->verif[j] != 0)
	{
		if (ant->verif[j] == i)
		{
			ant->i = ant->best_poss->nb_path + 1;
			ft_bzero(ant->verif, (sizeof(int) * ant->best_poss->nb_path));
			return (0);
		}
		j++;
	}
	if (j >= ant->best_poss->nb_path)
		ft_bzero(ant->verif, (sizeof(int) * ant->best_poss->nb_path));
	j = 0;
	while (j < ant->best_poss->nb_path)
	{
		if (ant->verif[j] == 0)
		{
			ant->verif[j] = i;
			break ;
		}
		j++;
	}
	if (j == ant->best_poss->nb_path - 1)
		ft_bzero(ant->verif, (sizeof(int) * ant->best_poss->nb_path));
	return (1);
}

static t_ant	*answer2(t_ant *ant, t_pawn *pawn, int i)
{
	t_room	*room;
	t_tab	*tab;

	if (pawn->check == 1 && verif_answer(ant, pawn->path->id, 0) == 0)
	{
		pawn->check--;
		return (ant);
	}
	tab = pawn->path->room;
	i = pawn->check;
	while (tab->next && pawn->check / 100 >= 1)
	{
		i -= 100;
		tab = tab->next;
	}
	room = tab->tab[i];
	write(1, "L", 1);
	ft_putnbr(pawn->id_pawn);
	write(1, "-", 1);
	ft_putstr(room->name);
	if (ant->i != ant->best_poss->nb_path)
		write(1, " ", 1);
	if (room == ant->end)
		pawn->check = -1;
	return (ant);
}

static t_pawn	*answer0(t_ant *ant, t_pawn *pawn)
{
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
			answer2(ant, pawn, 0);
		if (ant->i >= ant->best_poss->nb_path)
			break ;
		pawn = pawn->next;
	}
	return (pawn);
}

t_ant			*answer(t_ant *ant)
{
	t_pawn		*pawn;
	int			i;

	i = 0;
	pawn = ant->pawn;
	while (1)
	{
		i++;
		ant->i = 0;
		pawn = answer0(ant, pawn);
		pawn = ant->pawn;
		if (finish(ant))
			break ;
		write(1, "\n", 1);
	}
	printf("\n\nTurn = %d    Number path find = %d    Number path use = %d    "
	"Number ant = %d\n", i, ant->nb_path, ant->best_poss->nb_path, ant->nb_ant);
	return (ant);
}

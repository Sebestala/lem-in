/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:38:41 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/30 20:11:04 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant	tab_zero(t_ant ant)
{
	int	i;

	i = 1;
	ant.tab_id[0] = 1;
	while (i <= ant.nb_path)
	{
		ant.tab_id[i] = 0;
		i++;
	}
	return (ant);
}

t_ant	init_tab(t_ant ant)
{
	ant = init_ant(ant);
	if (!(ant.tab_id = (int *)malloc(sizeof(int) * (ant.nb_path + 1))))
		exit_str("Error : dynamic allocation problem in init_tab");
	ft_bzero(&ant.tab_id, (sizeof(int) * (ant.nb_path + 1)));
	return (ant);
}

static void		new_ptr_id(t_ant ant, t_path *path)
{
	t_ptr	ptr;

	ft_bzero(&ptr, sizeof(t_poss));
	while (ant.poss->next != NULL)
		ant.poss = ant.poss->next;
	while (ant.poss->id_path->next != NULL)
		ant.poss->id_path = ant.poss->id_path->next;
	if (ant.poss->id_path)
		ptr.back = ant.poss->id_path;
	ptr.ptr_path = path;
	ptr.id = path->id;
	ant.poss->id_path->next = &ptr;
}

static t_ant	new_poss2(t_ant ant)
{
	t_poss	poss2;

	ft_bzero(&poss2, sizeof(t_poss));
	while (ant.poss->next != NULL)
		ant.poss = ant.poss->next;
	ant.poss->next = &poss2;
	poss2.id_poss = ant.poss->id_poss + 1;
	poss2.nb_path = ant.poss->nb_path;
	poss2.total_power = ant.poss->total_power;
	return (ant);
}

static t_ant	start_poss(t_ant ant)
{
	ant.j = 1;
	t_poss	poss;
	ft_bzero(&poss, sizeof(t_poss));
	ant.poss = &poss;
	poss.id_poss = 1;
	poss.nb_path = 1;
	poss.total_power = ant.path->ptr_path->power;
	new_ptr_id(ant, ant.path->ptr_path);
	ant = new_poss2(ant);
	return (ant);
}

static t_poss	*new_value(t_ant ant, t_poss *poss)
{
	ant.i = 0;
	poss->nb_path = 0;
	poss->total_power = 0;
	while (poss->id_path != NULL)
	{
		poss->nb_path++;
		poss->total_power += poss->id_path->ptr_path->power;
		poss->id_path = poss->id_path->next;
	}
	return (poss);
}

static t_poss	*modif_tab(t_ant ant, t_poss *poss, int id)
{
	int		i;

	i = 0;
	while (i < id)
	{
		ant.tab_id[i] = 1;
		i++;
	}
	while (poss->id_path != NULL)
	{
		while (poss->id_path->ptr_path->id_path != NULL)
		{
			ant.tab_id[poss->id_path->ptr_path->id_path->id] = 1;
			poss->id_path->ptr_path->id_path =
				poss->id_path->ptr_path->id_path->next;
		}
		poss->id_path = poss->id_path->next;
	}
	return (poss);
}

static t_ant		del_path(t_ant ant, t_poss *poss)
{
	t_ptr	*ptr;

	while (poss->id_path->next->next != NULL)
		poss->id_path = poss->id_path->next;
	ptr = poss->id_path->next;
	poss->id_path->next = NULL;
	free(ptr);
	ft_bzero(&ptr, sizeof(t_ptr));
	ptr = NULL;
	ant.j = poss->id_path->ptr_path->id + 1;
	return (ant);
}


static void		new_poss(t_ant ant, int id)
{
	while (ant.path->ptr_path->id != id)
		ant.path = ant.path->next;
	new_ptr_id(ant, ant.path->ptr_path);
	ant = new_poss2(ant);
}

t_ant			possibility(t_ant ant)
{
	while (ant.path->next != NULL)
		ant.path = ant.path->next;
	ant.nb_path = ant.path->ptr_path->id;
	ant = start_poss(ant);
	while (ant.poss->nb_path != 0)
	{
		ant.poss = new_value(ant, ant.poss);
		ant.poss = modif_tab(ant, ant.poss, ant.j);
		while (1)
		{
			if (ant.tab_id[ant.i] == 0)
			{
				new_poss(ant, ant.i);
				ant.poss = ant.poss->next;
				break ;
			}
			ant.i++;
			if (ant.i > ant.nb_path + 1)
			{
				ant = del_path(ant, ant.poss);
				break ;
			}
		}
	}
}

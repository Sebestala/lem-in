/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 16:23:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/29 16:23:43 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_path		*del_path2(t_ant *ant, int id)
{
	t_tab2	*tab2;
	t_path	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j >= 0 && ant->path[i])
	{
		j = 0;
		tab2 = ant->path[i];
		while (j >= 0 && tab2->tab2[j])
		{
			path = tab2->tab2[j];
			if (id == path->id)
				j = -2;
			j++;
		}
		i++;
	}
	return (path);
}

void		new_ptr_id(t_ant *ant, t_path *path)
{
	t_ptr	*ptr;
	t_poss	*poss;
	t_ptr	*ptr1;

	poss = ant->poss_end;
	ptr = memalloc_sterr(sizeof(t_ptr), "new_ptr_id");
	ptr1 = poss->id_path;
	while (ptr1 && ptr1->next)
		ptr1 = ptr1->next;
	if (!ptr1)
		poss->id_path = ptr;
	else
		ptr1->next = ptr;
	ptr->ptr_path = path;
	ptr->id = path->id;
}

t_poss		*new_value(t_ant *ant, t_poss *poss)
{
	t_ptr	*ptr;

	ptr = poss->id_path;
	ant->i = 1;
	poss->nb_path = 0;
	poss->total_power = 0;
	while (ptr != NULL)
	{
		poss->nb_path++;
		poss->total_power += ptr->ptr_path->power;
		ptr = ptr->next;
	}
	return (poss);
}

t_ant		*copy_poss(t_ant *ant)
{
	t_poss	*copy;
	t_poss	*poss;
	t_ptr	*ptr;

	poss = ant->poss_end;
	copy = memalloc_sterr(sizeof(t_poss), "new_poss2");
	poss = new_value(ant, poss);
	poss->next = copy;
	ant->poss_end = copy;
	copy->id_poss = poss->id_poss + 1;
	copy->nb_path = poss->nb_path;
	copy->total_power = poss->total_power;
	ptr = poss->id_path;
	while (ptr != NULL)
	{
		new_ptr_id(ant, ptr->ptr_path);
		ptr = ptr->next;
	}
	return (ant);
}

t_ant		*start_poss(t_ant *ant)
{
	t_poss		*poss;
	t_path		*path;
	t_tab2		*tab2;

	tab2 = ant->path[0];
	path = tab2->tab2[0];
	poss = memalloc_sterr(sizeof(t_poss), "start_poss");
	ant->poss = poss;
	ant->poss_end = poss;
	poss->id_poss = 1;
	poss->nb_path = 1;
	poss->total_power = path->power;
	new_ptr_id(ant, path);
	ant = copy_poss(ant);
	return (ant);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:38:41 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:45:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static void		new_ptr_id(t_ant *ant, t_path *path)
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

static t_poss	*new_value(t_ant *ant, t_poss *poss)
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

static t_ant	*copy_poss(t_ant *ant)
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

static t_ant	*start_poss(t_ant *ant)
{
	t_poss		*poss;

	poss = memalloc_sterr(sizeof(t_poss), "start_poss");
	ant->poss = poss;
	ant->poss_end = poss;
	poss->id_poss = 1;
	poss->nb_path = 1;
	poss->total_power = ant->path->power;
	new_ptr_id(ant, ant->path);
	ant = copy_poss(ant);
	return (ant);
}

static t_poss	*modif_tab(t_ant *ant, t_poss *poss, int id)
{
	int		i;
	t_ptr	*ptr;

	ptr = poss->id_path;
	i = 0;
	while (i <= ant->nb_path + 1)
		ant->tab_id[i++] = '0';
	i = 0;
	while (i <= id || i <= poss->id_path->id)
		ant->tab_id[i++] = '1';
	while (ptr != NULL)
	{
		i = 0;
		while (ptr->ptr_path->id_path[i])
		{
			if (ptr->ptr_path->id_path[i] == '1')
				ant->tab_id[i] = '1';
			i++;
		}
		ptr = ptr->next;
	}
	return (poss);
}

static t_ant	*del_path(t_ant *ant, t_poss *poss)
{
	t_path	*ptr;
	t_ptr	*ptr1;
	t_ptr	*ptr3;

	poss = new_value(ant, poss);
	ptr1 = poss->id_path;
	if (poss->nb_path == 1)
	{
		ptr1->id++;
		if (ptr1->id > ant->nb_path)
		{
			poss->nb_path = 0;
			return (ant);
		}
		ptr = ant->path;
		while (ptr && ptr1->id != ptr->id)
			ptr = ptr->next;
		ptr1->ptr_path = ptr;
		ant->j = ptr1->id;
		ant = copy_poss(ant);
		return (ant);
	}
	ptr1 = poss->id_path;
	while (ptr1 && ptr1->next->next)
		ptr1 = ptr1->next;
	ptr3 = ptr1->next;
	ant->j = ptr3->id;
	ptr1->next = NULL;
	memdel_zero(ptr3, sizeof(t_ptr));
	return (ant);
}

static void		new_poss(t_ant *ant, int id)
{
	t_path	*path;

	path = ant->path;
	while (path->id != id)
		path = path->next;
	new_ptr_id(ant, path);
	ant = copy_poss(ant);
}

t_ant			*possibility(t_ant *ant)
{
	t_poss	*poss;

	ant->tab_id = memalloc_sterr((ant->nb_path + 2) * sizeof(char), "main");
	ant = start_poss(ant);
	poss = ant->poss->next;
	while (poss->nb_path != 0)
	{
		poss = modif_tab(ant, poss, ant->j);
		ant->i = 1;
		while (1)
		{
			if (ant->tab_id[ant->i] == '0')
			{
				new_poss(ant, ant->i);
				break ;
			}
			ant->i++;
			if (ant->i > ant->nb_path)
			{
				ant = del_path(ant, poss);
				break ;
			}
		}
		if (poss->next != NULL)
			poss = poss->next;
	}
	return (ant);
}

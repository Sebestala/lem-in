/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:38:41 by sgarcia           #+#    #+#             */
/*   Updated: 2018/10/01 19:50:46 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_poss	*modif_tab(t_ant *ant, t_poss *poss, int id)
{
	int		i;
	t_ptr	*ptr;

	ptr = poss->id_path;
	i = 0;
	while (i <= ant->nb_path)
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

static t_ant	*del_path1(t_ant *ant, t_poss *poss, t_ptr *ptr1)
{
	t_path	*ptr;

	ptr1->id++;
	if (ptr1->id > ant->nb_path)
	{
		poss->nb_path = 0;
		return (ant);
	}
	ptr = del_path2(ant, ptr1->id);
	ptr1->ptr_path = ptr;
	ant->j = ptr1->id;
	ant = copy_poss(ant);
	return (ant);
}

static t_ant	*del_path(t_ant *ant, t_poss *poss)
{
	t_ptr	*ptr1;
	t_ptr	*ptr3;

	poss = new_value(ant, poss);
	ptr1 = poss->id_path;
	if (poss->nb_path == 1)
		return (del_path1(ant, poss, ptr1));
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
	t_tab2	*tab2;
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
			if (path->id == id)
				j = -2;
			j++;
		}
		i++;
	}
	new_ptr_id(ant, path);
	ant = copy_poss(ant);
}

t_ant			*possibility(t_ant *ant, t_poss *poss)
{
	ant->tab_id = memalloc_sterr((ant->nb_path + 1) * sizeof(char), "main");
	ant = start_poss(ant);
	poss = ant->poss->next;
	while (poss->nb_path != 0 && ant->poss_end->id_poss < 1000000)
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
